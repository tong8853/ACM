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
int in[5005], out[5005];
ll dp[5005];
queue<int> q;

void solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        out[u]++, in[v]++;
    }
    rep(i, 1, n){
        if(in[i] == 0){//起点
            dp[i] = 1;
            q.push(i);
        }
    }

    ll ans = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            dp[v] += dp[u];
            dp[v] %= mod;
            in[v]--;
            if(in[v] == 0){ //说明前面没有依赖关系了
                q.push(v);
            }
        }
    }

    rep(i, 1, n){
        if(out[i] == 0){
            ans += dp[i];
            ans %= mod;
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