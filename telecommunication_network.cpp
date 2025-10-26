#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
    long long risk;
};

struct State {
    int node;
    long long dist;
    
    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

// Check if there's a path from 1 to N with max risk <= maxRisk
// Returns the shortest total time if path exists, -1 otherwise
long long canReach(int n, vector<vector<Edge>>& adj, long long maxRisk) {
    vector<long long> dist(n + 1, INF);
    priority_queue<State, vector<State>, greater<State>> pq;
    
    dist[1] = 0;
    pq.push({1, 0});
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        int u = current.node;
        long long d = current.dist;
        
        if (d > dist[u]) continue;
        if (u == n) return d; // Found path to destination
        
        for (const Edge& edge : adj[u]) {
            if (edge.risk > maxRisk) continue; // Skip edges with too high risk
            
            int v = edge.to;
            long long newDist = d + edge.weight;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({v, newDist});
            }
        }
    }
    
    return -1; // No path found
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> adj(n + 1);
    set<long long> risks;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w, r;
        cin >> u >> v >> w >> r;
        
        adj[u].push_back({v, w, r});
        adj[v].push_back({u, w, r});
        risks.insert(r);
    }
    
    // Binary search on maximum risk
    vector<long long> riskValues(risks.begin(), risks.end());
    long long left = 0, right = riskValues.size() - 1;
    long long bestMaxRisk = -1;
    long long bestTotalTime = INF;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long currentMaxRisk = riskValues[mid];
        
        long long totalTime = canReach(n, adj, currentMaxRisk);
        
        if (totalTime != -1) {
            // Path exists with this max risk
            bestMaxRisk = currentMaxRisk;
            bestTotalTime = totalTime;
            right = mid - 1; // Try smaller max risk
        } else {
            // No path with this max risk, try larger
            left = mid + 1;
        }
    }
    
    if (bestMaxRisk == -1) {
        cout << -1 << "\n";
    } else {
        cout << bestMaxRisk << " " << bestTotalTime << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
