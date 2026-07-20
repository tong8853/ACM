#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const ll mod = 998244353;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<vll> dp(n + 1, vll(6));    dp[i][j] 表示长度为i,mod值为j的方案数
    dp[0][0] = 1;
    rep(i, 1, n){
        ll x = s[i] - '0';
        rep(j, 0, 5){
            dp[i][j] = dp[i - 1][j];
        }
        rep(j, 0, 5){
            dp[i][(j * 10 + x) % 6] += dp[i - 1][j];
            dp[i][(j * 10 + x) % 6] %= mod;
        }
    }
    cout << (dp[n][0] - 1 + mod) % mod << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}