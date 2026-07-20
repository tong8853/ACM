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
    int n, vsum; 
    cin >> n >> vsum;
    vi v(n + 1), w(n + 1);
    rep(i, 1, n) cin >> v[i] >> w[i];
    vi dp1(vsum + 1);
    rep(i, 1, n){
        rep2(j, vsum, v[i]){ 
            dp1[j] = max(dp1[j], dp1[j - v[i]] + w[i]);
        }
    }
    cout << dp1[vsum] << endl;

    vi dp2(vsum + 1, -INT_MAX);
    dp2[0] = 0;
    rep(i, 1, n){
        rep2(j, vsum, v[i]){
            dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
        }
    }
    cout << (dp2[vsum] > 0 ? dp2[vsum] : 0) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}