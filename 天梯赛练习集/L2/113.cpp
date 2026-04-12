#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define rep(i, a, b) for(int i = (a); i <= b; ++i)

void solve(){
    int n, m, s, d;cin >> n >> m >> s >> d;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<vi> uv(n + 1, vi(n + 1, INF));
    rep(i, 1, m){
        int u, v, w;cin >> u >> v >> w;
        uv[u][v] = w, uv[v][u] = w;
    }
    //Dijkstra相关变量
    vi dis(n, INF), cnt(n, 0), w(n, 0), pre(n, -1), vis(n, 0);
    dis[s] = 0;
    cnt[s] = 1;
    rep(i, 0, n - 1){
        if()
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
}