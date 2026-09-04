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
    vi a;
    int x;
    while(cin >> x){
        a.push_back(x);
    }
    int n = a.size();
    
    rep(i, 0, n - 1){
        dp[i + 2] = max(dp[i] + a[i], dp[i + 1]);
    }
    cout << dp[n + 1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}