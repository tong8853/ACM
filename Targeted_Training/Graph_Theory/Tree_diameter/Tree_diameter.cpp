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
    int n, d = 0;
    cin >> n;
    vi dp(n + 1); //dp[i]表示以i为跟的子树中， 从i到叶子节点的最大深度
    vector<vi> g(n + 1);
    auto dfs = [&](auto self, int u, int fa)->void{
        for(int v : g[u]){
            if(v == fa) continue;
            self(self, v, u);
            d = max(d, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    };

    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(dfs, 1, 0);
    cout << d << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}