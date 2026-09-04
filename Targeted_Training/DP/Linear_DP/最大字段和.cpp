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
    vll a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    const int N = 2e5 + 10;
    ll dp[N];   //dp[i]表示以i结尾的最大字段和
    memset(dp, 0, sizeof(dp));
    ll ans = -LLONG_MAX;
    rep(i, 1, n){
        dp[i] = max(dp[i - 1] + a[i], a[i]); //继续接或者重新开始
        ans = max(ans, dp[i]);
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