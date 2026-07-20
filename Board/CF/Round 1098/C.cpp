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
    ll a, n;
    cin >> a >> n; // n = 2
    vi d(n);
    rep(i, 0, n - 1) cin >> d[i];
    ll len = to_string(a).size();
    
    ll ans = 1e18;
    // if(len > 1){
    //     string s1 = "";
    //     rep(i, 1, len - 1) s1 += to_string(b);
    //     ans = min(ans, llabs(a - stoll(s1)));
    // }
    
    // string s1 = "";
    // s1 += to_string(a == 0 ? b : a);
    // rep(i, 1, len) s1 += to_string(a);
    // ans = min(ans, llabs(x - stoll(s1)));
    

    auto dfs = [&](auto self, int i, ll cur){
        ans = min(ans, llabs(a - cur));
        if(i == len + 1) return;
    
        
        if(i == 0 && d[0] == 0) self(self, i + 1, cur * 10 + d[1]);
        else{
            self(self, i + 1, cur * 10 + d[0]);
            self(self, i + 1, cur * 10 + d[1]);
        }
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}