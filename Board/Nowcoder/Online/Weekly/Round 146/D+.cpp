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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vv<vv<ll>> dp(n + 1, vv<ll>(6));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        ll x = s[i] - '0';
        for (ll j = 0; j < 6; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (ll j = 0; j < 6; ++j) {
            dp[i][(j * 10 + x) % 6] += dp[i - 1][j];
            dp[i][(j * 10 + x) % 6] %= P;
        }
    }
    
    cout << (dp[n][0] - 1 + P) % P << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}