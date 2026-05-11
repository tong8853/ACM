#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define QAQ(x) cout << #x << ": " << (x) << endl, exit(0);
#define endl '\n'
#define int long long
using namespace std; // int => long long
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e9 + 7;
const int N = 4e5 + 5;
int n, m, k, s;
int a[N];
int dis[N][105];           // dis[i][j]: 第 i 个行星距离第 j 个资源点最近的距离

vector<int> g[N];

void bfs(int now) {
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        dis[i][now] = INF;
        if (a[i] == now) {
            Q.push(i);
            dis[i][now] = 0;
        }
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int v : g[u]) {
            if (dis[v][now] > dis[u][now] + 1) {
                dis[v][now] = dis[u][now] + 1;
                Q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= k; i++) bfs(i);

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        sort(dis[i] + 1, dis[i] + 1 + k);
        for (int j = 1; j <= s; j++)
            ans += dis[i][j];
        cout << ans << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}