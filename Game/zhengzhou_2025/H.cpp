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
    ll s, l, r;
    cin >> s >> l >> r;
    unordered_map<ll, ll> ok;
    auto dfs = [&](auto self, ll x){
        if(sqrt(x + 1) * sqrt(x + 1) != (x + 1)) return;
        ok[x] = 1;
        self(self, sqrt(x + 1));
        self(self, sqrt(x + 1) - 1);
    };
    dfs(dfs, s);
    ll ans = 0;
    for(auto &[x, y] : ok){
        if(x >= l && x <= r && y == 1){
            ans++;
        }
    }
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