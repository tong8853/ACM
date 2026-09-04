#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    vll a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll dp[N][2]; //dp[i][0]表示最后一个一定选，反之则一定不选
    memset(dp, 0, sizeof(dp));
    rep(i, 1, n){
        if(a[i] <= 0){ //小于0则这一段都不选，故直接由上一段的两个状态的最优状态转移过来即可
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }else{
            //如果这一段的最后一个一定选，则需要看上一段的最后一个是否选择来决定这段是选多少个
            dp[i][0] = max(dp[i - 1][0] + b[i] / 2 * a[i], dp[i - 1][1] + (b[i] + 1) / 2 * a[i]);
            dp[i][1] = max(dp[i - 1][0] + (b[i] - 1) / 2 * a[i], dp[i - 1][1] + b[i] / 2 * a[i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}