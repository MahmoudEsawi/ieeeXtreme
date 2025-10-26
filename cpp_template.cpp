/*
🏆 IEEE Xtreme Competition - C++ Template
Optimized for speed, memory efficiency, and competitive programming
*/

#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// 🚀 FAST I/O AND OPTIMIZATIONS
// =============================================================================

// Fast I/O
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

// Type definitions for convenience
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;

// =============================================================================
// 🔥 ESSENTIAL DATA STRUCTURES
// =============================================================================

class UnionFind {
private:
    vi parent, rank;
    int components;
    
public:
    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        
        components--;
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getComponents() { return components; }
};

class SegmentTree {
private:
    vll tree;
    int n;
    ll default_val;
    
    ll operation(ll a, ll b) {
        return max(a, b); // Change this for different operations
    }
    
    void build(const vll& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = operation(tree[2*node], tree[2*node+1]);
        }
    }
    
    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = operation(tree[2*node], tree[2*node+1]);
        }
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return default_val;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        ll left = query(2*node, start, mid, l, r);
        ll right = query(2*node+1, mid+1, end, l, r);
        return operation(left, right);
    }
    
public:
    SegmentTree(const vll& arr, ll default_val = 0) : n(arr.size()), default_val(default_val) {
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }
    
    void update(int idx, ll val) {
        update(1, 0, n-1, idx, val);
    }
    
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

// =============================================================================
// 🎯 GRAPH ALGORITHMS
// =============================================================================

vector<ll> dijkstra(const vector<vpii>& graph, int start) {
    int n = graph.size();
    vector<ll> dist(n, LLINF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int bfs_shortest_path(const vvi& graph, int start, int end) {
    if (start == end) return 0;
    
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    q.push(start);
    visited[start] = true;
    int distance = 0;
    
    while (!q.empty()) {
        int size = q.size();
        distance++;
        
        for (int i = 0; i < size; i++) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                if (v == end) return distance;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    return -1; // No path found
}

vi topological_sort(const vvi& graph) {
    int n = graph.size();
    vi in_degree(n, 0);
    
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vi result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return (result.size() == n) ? result : vi(); // Empty if cycle exists
}

// =============================================================================
// 🔢 DYNAMIC PROGRAMMING
// =============================================================================

ll knapsack_01(const vi& weights, const vi& values, int capacity) {
    int n = weights.size();
    vvll dp(n + 1, vll(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int longest_common_subsequence(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    vvi dp(m + 1, vi(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int longest_increasing_subsequence(const vi& arr) {
    vi tails;
    for (int num : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return tails.size();
}

// =============================================================================
// 🎨 MATHEMATICAL ALGORITHMS
// =============================================================================

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll gcd = extended_gcd(a, m, x, y);
    if (gcd != 1) return -1; // Modular inverse doesn't exist
    return (x % m + m) % m;
}

ll fast_power(ll base, ll exp, ll mod = LLINF) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    return is_prime;
}

// =============================================================================
// 🎯 STRING ALGORITHMS
// =============================================================================

vi kmp_search(const string& text, const string& pattern) {
    int m = pattern.length();
    vi lps(m, 0);
    
    // Build LPS array
    int len = 0;
    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        lps[i] = len;
    }
    
    // Search
    vi matches;
    int i = 0, j = 0;
    int n = text.length();
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }
        
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return matches;
}

vi manacher(const string& s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    
    int n = t.length();
    vi p(n, 0);
    int center = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        if (i < right) {
            p[i] = min(right - i, p[2 * center - i]);
        }
        
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && 
               t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    
    return p;
}

// =============================================================================
// 🚀 COMMON PROBLEM SOLVERS
// =============================================================================

pii two_sum(const vi& nums, int target) {
    unordered_map<int, int> num_to_index;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end()) {
            return {num_to_index[complement], i};
        }
        num_to_index[nums[i]] = i;
    }
    return {-1, -1};
}

vector<vi> three_sum(vi nums) {
    sort(nums.begin(), nums.end());
    vector<vi> result;
    int n = nums.size();
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1, right = n - 1;
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            if (total == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++; right--;
            } else if (total < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

ll max_subarray_sum(const vi& arr) {
    ll max_sum = arr[0];
    ll current_sum = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        current_sum = max((ll)arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}

// =============================================================================
// 🎯 MAIN TEMPLATE
// =============================================================================

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Your solution here
    ll result = max_subarray_sum(arr);
    cout << result << endl;
}

int main() {
    fastio;
    
    // Uncomment for single test case
    // solve();
    
    // For multiple test cases
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
