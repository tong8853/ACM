#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll coef;  // +1 or -1 for x
    ll cons;  // constant term: b_i = coef * x + cons
};

vector<vector<pair<int, ll>>> adj;
vector<Node> nodes;
bool possible = true;

void dfs(int u, int parent, ll coef_u, ll cons_u) {
    nodes[u] = {coef_u, cons_u};
    
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        // b_v = w - b_u
        ll coef_v = -coef_u;
        ll cons_v = w - cons_u;
        dfs(v, u, coef_v, cons_v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    if (n == 1) {
        cout << "YES\n1\n";
        return 0;
    }
    
    nodes.resize(n + 1);
    // Root at 1, b1 = x  => coef=1, cons=0
    dfs(1, -1, 1, 0);
    
    // Now collect constraints for x
    // For each node i: 1 <= b_i <= 1e9
    ll low = LLONG_MIN / 2;  // x >= low
    ll high = LLONG_MAX / 2; // x <= high
    
    for (int i = 1; i <= n; i++) {
        ll c = nodes[i].coef;
        ll t = nodes[i].cons;
        
        // b = c * x + t
        // 1 <= c*x + t <= 1e9
        
        if (c == 1) {
            // x + t >= 1  => x >= 1 - t
            // x + t <= 1e9 => x <= 1e9 - t
            low = max(low, 1 - t);
            high = min(high, 1000000000LL - t);
        } else {  // c == -1
            // -x + t >= 1 => -x >= 1 - t => x <= t - 1
            // -x + t <= 1e9 => -x <= 1e9 - t => x >= t - 1e9
            low = max(low, t - 1000000000LL);
            high = min(high, t - 1);
        }
    }
    
    if (low > high) {
        cout << "NO\n";
        return 0;
    }
    
    // Choose any x in [low, high], prefer small positive if possible
    ll x = max(low, 1LL);  // try positive
    if (x > high) x = low;
    
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        ll bi = nodes[i].coef * x + nodes[i].cons;
        if (i > 1) cout << " ";
        cout << bi;
    }
    cout << "\n";
    
    return 0;
}