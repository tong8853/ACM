#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 676767677;
void solve(){
    int n;cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll ans = 0;
    rep(i, 1, n){
        if(i != n && a[i] == 1) continue;
        ans += a[i];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}