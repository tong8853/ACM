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
    int t;
    cin >> t;
    vi n(t + 1), k(t + 1);
    int mn = 0;
    rep(i, 1, t){
        cin >> n[i] >> k[i];
        mn = max(n[i], mn);
    } 
    vi dp(mn + 1);
    rep(i, 1, mn){
        if(i % 2) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i / 2] + 1;
    }
    rep(i, 1, t){
        int m = n[i];
        int ans = 0;
        rep(j, 1, m){
            if(dp[j] > k[i]) ans++;
        }
        cout << ans << endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}