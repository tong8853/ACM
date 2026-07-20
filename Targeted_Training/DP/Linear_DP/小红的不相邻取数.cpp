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
    vi a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i] >> b[i];
    ll dp[N][2]; //dp[i][0]表示不选最后一个，反之则选
    memset(dp, 0, sizeof(dp));
    rep(i, 1, n){
        if(a[i] < 0){
            
        }else{

        }
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