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
    ll dp[3];
    memset(dp, 0, sizeof(dp));
    string s;
    cin >> s;
    int m = s.size();
    s = " " + s;
    dp[0] = 1;
    const ll mod = 1e9 + 7;
    rep(i, 1, m){
        ll c = (s[i] - '0') % 3;
        ll nextdp[3];
        memset(nextdp, 0, sizeof(nextdp));

        rep(j, 0, 2) nextdp[j] = (dp[(j - c + 3) % 3] % mod + dp[j] % mod) % mod;
        rep(j, 0, 2) dp[j] = nextdp[j];
    }
    cout << (dp[0] - 1 + mod) % mod << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}