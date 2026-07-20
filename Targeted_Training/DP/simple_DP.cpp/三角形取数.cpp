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
    int n, k;
    cin >> n >> k;
    vector<vll> a(n + 1, vll(2 * n + 1));
    rep(i, 1, n){
        rep(j, 1, 2 * i - 1){
            cin >> a[i][j];
        }
    }

    //设dp[i][j]为走到i, j的最大数值之和； 中心为i,偏移为k
    vector<vector<ll>> dp(n + 1, vll(2 * n, -2e16));
    int l = (n - k >= 1 ? n - k : 1);
    int r = (n + k <= 2 * n - 1 ? n + k : 2 * n - 1);
    rep(i, l, r) dp[n][i] = a[n][i];
    rep2(i, n - 1, 1){
        rep(j, 1, 2 * i - 1){
            dp[i][j] = max({dp[i + 1][j + 2], dp[i + 1][j + 1], dp[i + 1][j]}) + a[i][j];
        }
    }
    cout << dp[1][1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}