#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 100003;

void solve(){
    ll n, k;
    cin >> n >> k;
    vll dp(n + 1);
    dp[0] = 1;
    auto dfs = [&](auto self, int i) -> int{
        if(i < 0) return 0;
        if(dp[i]) return dp[i];
        ll sum = 0;
        rep(j, i - k, i - 1) sum = (sum + self(self, j)) % mod;
        return dp[i] = sum; 
    };
    dfs(dfs, n);
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