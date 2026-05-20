#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define debug(x) cout<<#x<<":"<<x<<endl;
#define sep cout<<endl<<endl;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int, ll>>> edge(n + 1);
    rep(i, 1, n - 1){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    //令第一个节点的值为x, 而后dfs下去，算出其他节点的关于x的表达式
    
    vi vis(n + 1);
    vector<pair<ll, ll>> val(n + 1); //{a, b}， val[i] = a * x + b, val[1] = x;
    val[1] = {1, 0};

    auto dfs = [&](auto self, int u) -> void{
        vis[u] = 1;
        for(auto &[v, w] : edge[u]){
            if(!vis[v]){
                val[v].first = -val[u].first;
                val[v].second = w - val[u].second;
                self(self, v);
            }
        }
    };

    dfs(dfs, 1);
    ll L = 1, R = 1e9;
    rep(i, 1, n){
        ll a = val[i].first;
        ll b = val[i].second;
        if(a == 1){
            L = max(L, 1-b);
            R = min(R, (ll)1e9 - b);
        }else{
            L = max(L, b - (ll)1e9);
            R = min(R, b-1);
        }
    }
    if(L > R) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        rep(i, 1, n){
            cout << val[i].first * L + val[i].second << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}