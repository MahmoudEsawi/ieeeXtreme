#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

// --- Constants ---
const int MAXN = 100005;
typedef pair<long long, long long> HashPair;

const long long BASE1 = 31;
const long long MOD1 = 1e9 + 7;
const long long BASE2 = 37;
const long long MOD2 = 1e9 + 9;

// --- Globals ---
vector<int> adj[MAXN];
HashPair hash_down[MAXN];
HashPair hash_up[MAXN];
int parent[MAXN];
vector<int> children[MAXN];

// Precomputed powers for optimization
long long powers1[MAXN];
long long powers2[MAXN];

// --- Optimized Hashing Functions ---

void precompute_powers() {
    powers1[0] = 1;
    powers2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        powers1[i] = (powers1[i - 1] * BASE1) % MOD1;
        powers2[i] = (powers2[i - 1] * BASE2) % MOD2;
    }
}

// Optimized hash combination using polynomial rolling hash
HashPair combine_hashes(const vector<HashPair>& hashes) {
    if (hashes.empty()) return {1, 1};
    
    long long h1 = 1, h2 = 1;
    for (const auto& h : hashes) {
        h1 = (h1 * BASE1 + h.first) % MOD1;
        h2 = (h2 * BASE2 + h.second) % MOD2;
    }
    return {h1, h2};
}

// Fast hash combination for two elements
HashPair combine_two_hashes(const HashPair& h1, const HashPair& h2) {
    long long result1 = (h1.first * BASE1 + h2.first) % MOD1;
    long long result2 = (h1.second * BASE2 + h2.second) % MOD2;
    if (result1 < 0) result1 += MOD1;
    if (result2 < 0) result2 += MOD2;
    return {result1, result2};
}

// --- Optimized DFS Pass 1 ---
void dfs_down_iterative(int root) {
    stack<pair<int, bool>> s;
    s.push({root, false});
    
    vector<int> post_order_nodes;
    int p[MAXN] = {0};
    
    while (!s.empty()) {
        int u = s.top().first;
        bool visited_children = s.top().second;
        
        if (!visited_children) {
            s.top().second = true;
            for (int v : adj[u]) {
                if (v != p[u]) {
                    p[v] = u;
                    parent[v] = u;
                    children[u].push_back(v);
                    s.push({v, false});
                }
            }
        } else {
            s.pop();
            post_order_nodes.push_back(u);
        }
    }
    
    // Process in post-order with optimized sorting
    for (int u : post_order_nodes) {
        if (children[u].empty()) {
            hash_down[u] = {1, 1}; // Leaf node
        } else {
            vector<HashPair> children_hashes;
            children_hashes.reserve(children[u].size());
            
            for (int v : children[u]) {
                children_hashes.push_back(hash_down[v]);
            }
            
            // Sort for canonical form
            sort(children_hashes.begin(), children_hashes.end());
            hash_down[u] = combine_hashes(children_hashes);
        }
    }
}

// --- Optimized DFS Pass 2 (O(k) instead of O(k²)) ---
void dfs_up_iterative(int root) {
    stack<pair<int, HashPair>> s;
    s.push({root, {1, 1}});

    while (!s.empty()) {
        int u = s.top().first;
        HashPair hash_from_parent = s.top().second;
        s.pop();

        hash_up[u] = hash_from_parent;

        int k = children[u].size();
        if (k == 0) continue;

        // Pre-compute all children hashes and sort them
        vector<HashPair> children_hashes;
        children_hashes.reserve(k);
        
        for (int v : children[u]) {
            children_hashes.push_back(hash_down[v]);
        }
        sort(children_hashes.begin(), children_hashes.end());

        // For small k, use the original O(k²) approach to avoid complexity
        if (k <= 10) {
            for (int i = 0; i < k; i++) {
                int v = children[u][i];
                
                vector<HashPair> siblings_hashes;
                for (int j = 0; j < k; j++) {
                    if (i == j) continue;
                    siblings_hashes.push_back(children_hashes[j]);
                }
                sort(siblings_hashes.begin(), siblings_hashes.end());
                
                vector<HashPair> to_combine = {hash_from_parent, combine_hashes(siblings_hashes)};
                sort(to_combine.begin(), to_combine.end());
                HashPair hash_to_pass = combine_hashes(to_combine);
                
                s.push({v, hash_to_pass});
            }
        } else {
            // Use O(k) approach for large k
            vector<HashPair> prefix_hashes(k + 1), suffix_hashes(k + 1);
            
            // Prefix hashes: prefix_hashes[i] = hash of first i children
            prefix_hashes[0] = {1, 1};
            for (int i = 0; i < k; i++) {
                prefix_hashes[i + 1] = combine_two_hashes(prefix_hashes[i], children_hashes[i]);
            }
            
            // Suffix hashes: suffix_hashes[i] = hash of children from i to end
            suffix_hashes[k] = {1, 1};
            for (int i = k - 1; i >= 0; i--) {
                suffix_hashes[i] = combine_two_hashes(children_hashes[i], suffix_hashes[i + 1]);
            }

            // Now compute hash for each child in O(1) per child
            for (int i = 0; i < k; i++) {
                int v = children[u][i];
                
                // Hash of siblings = combine(prefix[i], suffix[i+1])
                HashPair siblings_hash = combine_two_hashes(prefix_hashes[i], suffix_hashes[i + 1]);
                
                // Final hash = combine(hash_from_parent, siblings_hash)
                vector<HashPair> to_combine = {hash_from_parent, siblings_hash};
                sort(to_combine.begin(), to_combine.end());
                HashPair hash_to_pass = combine_hashes(to_combine);
                
                s.push({v, hash_to_pass});
            }
        }
    }
}

// --- Main ---
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute_powers();

    int N;
    if (!(cin >> N) || N <= 0 || N > MAXN) return 0;

    // Reserve space for adjacency lists
    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        adj[i].reserve(10); // Typical tree node degree
        children[i].clear();
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return 0;
        if (u < 1 || u > N || v < 1 || v > N) return 0;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize hash arrays
    for (int i = 1; i <= N; i++) {
        hash_down[i] = {0, 0};
        hash_up[i] = {0, 0};
        parent[i] = 0;
    }

    dfs_down_iterative(1); 
    dfs_up_iterative(1);

    // Use map for orbit counting
    map<HashPair, int> orbit_counts;
    for (int i = 1; i <= N; ++i) {
        // Combine down and up hashes into a single hash
        vector<HashPair> combined = {hash_down[i], hash_up[i]};
        sort(combined.begin(), combined.end());
        HashPair combined_hash = combine_hashes(combined);
        orbit_counts[combined_hash]++;
    }

    int unique_node_count = 0;
    for (const auto& pair : orbit_counts) {
        if (pair.second == 1) {
            unique_node_count++;
        }
    }

    cout << unique_node_count << "\n";
    return 0;
}
