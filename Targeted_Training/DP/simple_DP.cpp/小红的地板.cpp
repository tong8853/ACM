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
    rep(i, 1, n) cin >> a[i];
    vi dp(n + 1);
    dp[1] = 0;
    rep(i, 2, n){
        if(i > 2) dp[i] = min(dp[i - 2], dp[i - 1]) + a[i];
        else dp[i] = dp[i - 1] + a[i];
    }
    cout << dp[n] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}