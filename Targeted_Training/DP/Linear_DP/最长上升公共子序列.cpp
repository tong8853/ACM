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
    int n;
    cin >> n;
    vll a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    const int N = 3005;
    ll dp[N][N]; //dp[i][j]表示a序列前i个数字b序列前j个数字，以b[j]结尾的最长公共上升子序列长度
    memset(dp, 0, sizeof(dp));
    ll ans = 0;
    rep(i, 1, n){
        rep(j, 1, n){
            //ai ！= bi， 因为是以bi结尾的，所以把ai去掉不影响，所以dp(i, j) = dp(i - 1, j)
            if(a[i] != b[j]) dp[i][j] = dp[i - 1][j];
            else{ //ai == bi， 只需要在前面找到一个可以把bj接上去的最长公共上升子序列即可
                ll mx = 0;
                rep(k, 1, j - 1){
                    if(b[k] < b[j]) mx = max(mx, dp[i - 1][k]);
                }
                dp[i][j] = mx + 1;
            }
            ans = max(ans, dp[i][j]);
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