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
    vll dp(50000005);
    ll m;
    cin >> m;
    auto dfs = [&](auto self, ll i){
        if(dp[i]) return dp[i];
        if(i == 1 || i == 2) return dp[i] = 1;
        else return dp[i] = (self(self, i - 1) + self(self, i - 2)) % m;
    };

    ll i = 1;
    while(!(dfs(dfs, i) == 0 && dfs(dfs, i + 1) == 1)){
        i++;
    }
    cout << i << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}