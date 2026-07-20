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
    //定义dp[i]为以ai结尾的子数组的最大值, dp[i] = max(dp[i - 1] + a[i], a[i]);
    vll dp(n + 1, -INT_MAX);
    rep(i, 1, n){
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}