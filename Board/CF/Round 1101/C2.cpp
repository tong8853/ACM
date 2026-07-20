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
    int n, x, s;
    cin >> n >> x >> s;
    string s1;
    cin >> s1;

    vi dp(x + 1, -1);
    dp[0] = 0;

    rep(i, 0, n - 1) {
        vi next_dp = dp;
        char c = s1[i];

        rep(k, 0, x) {
            if (dp[k] == -1) continue;

            int m = dp[k];
            ll  mm = 1LL * k * s - m;

            if (c == 'I') {
                if (k < x) {
                    next_dp[k + 1] = max(next_dp[k + 1], m + 1);
                }
            } else if (c == 'E') {
                if ( mm > 0) {
                    next_dp[k] = max(next_dp[k], m + 1);
                }
            } else if (c == 'A') {
                if (k < x) {
                    next_dp[k + 1] = max(next_dp[k + 1], m + 1);
                }
                if ( mm > 0) {
                    next_dp[k] = max(next_dp[k], m + 1);
                }
            }
        }
        dp = next_dp;
    }

    int ans = 0;
    rep(k, 0, x) {
        ans = max(ans, dp[k]);
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