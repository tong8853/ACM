//https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
using vi = vector<int>;

struct Edge{
    int to, weight;
};

struct node{
    int id, dis;
    // 优先队列默认大顶堆，我们要最小堆，所以重载大于号
    bool operator > (const node& b) const {
        return dis > b.dis;
    }
};

void solve(){
    int n, m, s;
    cin >> n >> m >> s;
    
    vector<vector<Edge>> adj(n + 1);
    rep(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vi dis(n + 1, INF);
    vector<bool> vis(n + 1, false);
    dis[s] = 0;

    // 堆优化：priority_queue<类型, 容器, 比较方式>
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({s, 0});

    while (!pq.empty()) {
        node top = pq.top();
        pq.pop();
        int u = top.id;

        if (vis[u]) continue;
        vis[u] = true;

        for (auto& edge : adj[u]) {
            int v = edge.to;
            if (dis[u] != INF && dis[u] + edge.weight < dis[v]) {
                dis[v] = dis[u] + edge.weight;
                pq.push({v, dis[v]});
            }
        }
    }

    rep(i, 1, n) {
        cout << dis[i] << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}