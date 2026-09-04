#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 80112002;
int n, m;
vi g[5005];
int ind[5005], out[5005];
ll dp[5005];

void solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ind[v]++;
    }

    auto dfs = [&](auto self, int i) -> int{
        if(dp[i]) return dp[i];
        if(g[i].empty()) return dp[i] = 1;
        
        for(auto v : g[i]){
            dp[i] = (dp[i] + self(self, v)) % mod;
        }
        return dp[i];
    };

    ll ans = 0;
    rep(i, 1, n){
        if(ind[i] == 0){
            ans = (ans + dfs(dfs, i)) % mod;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}