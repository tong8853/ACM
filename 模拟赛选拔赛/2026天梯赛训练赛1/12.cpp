#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define debug(x) std::cout << #x << " : " << x << "\n";
#define debug2(x,y) std::cout << #x << " : " << x << " " << #y << " : " << y << "\n";

void solve()
{
    // 先搜出最短路，或者直接预处理出所有最短路（Floyd）
    // 对于每个可达点，我们需要了解其各个最短路的 p 之和的最大值
    // 直接使用 BFS 暴力，判断到达各个点时是否满足预处理出来的最短路，如果是，则记录其路径的 p 总值
    // 最后对各个可达点的 p 总值处理，输出最大的
    int b, n, m, q; cin >> b >> n >> m >> q;
    int INF = (int)4e18;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> mx(n + 1, vector<int>(n + 1, -INF));
    rep(i, 1, n) {
        dist[i][i] = 0;
        mx[i][i] = 0;
    }
    rep(i, 1, m) {
        int u, v, w, p; cin >> u >> v >> w >> p;
        if (w < dist[u][v]) {
            dist[u][v] = dist[v][u] = w;
            mx[u][v] = mx[v][u] = p;
        }
        else if (w == dist[u][v]) {
            mx[u][v] = max(mx[u][v], p);
            mx[v][u] = max(mx[v][u], p);
        }
    }
    rep(k, 1, n) {
        rep(i, 1, n) {
            if (dist[i][k] == INF) continue;
            rep(j, 1, n) {
                if (dist[k][j] == INF) continue;
                int val = dist[i][k] + dist[k][j];
                int happy = mx[i][k] + mx[k][j];
                if (val < dist[i][j]) {
                    dist[i][j] = val;
                    mx[i][j] = happy;
                }
                else if (val == dist[i][j]) {
                    mx[i][j] = max(mx[i][j], happy);
                }
            }
        }
    }
    while (q--) {
        int root; cin >> root;
        vector<int> vals;
        int best = -1;
        rep(i, 1, n) {
            if (i == root) continue;
            if (dist[root][i] <= b) {
                vals.push_back(i);
                best = max(best, mx[root][i]);
            }
        }

        if (vals.empty()) {
            cout << "T_T\n";
            continue;
        }
        for (int i = 0; i < (int)vals.size(); ++i) {
            if (i) cout << ' ';
            cout << vals[i];
        }
        cout << '\n';
        bool f = 1;
        rep(i, 1, n) {
            if (i == root) continue;
            if (dist[root][i] <= b && mx[root][i] == best) {
                if (!f) cout << ' ';
                cout << i;
                f = 0;
            }
        }
        cout << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    // cout<<std::fixed<<std::setprecision(10);
    std::cin.tie(0);
    int t__ = 1;
    //cin >> t__;
    while (t__--)
        solve();
    return 0;
}