#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vi d(n + 1);
    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c; //维护一个直径端点
    auto dfs = [&](auto self, int u, int fa)->void{
        for(int v : g[u]){
            if(v == fa) continue;
            d[v] = d[u] + 1;
            if(d[v] > d[c]) c = v;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, 0);
    d[c] = 0;
    dfs(dfs, c, 0);
    cout << d[c] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}