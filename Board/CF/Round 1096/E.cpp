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
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi suf(n);
    rep2(i, n - 1, 0){
        if(i == n - 1) suf[i] = a[i];
        else suf[i] = min(a[i], suf[i + 1]);
    }
    int mx = -1, cur = 1;
    rep(i, 1, n - 1){
        if(suf[i] == suf[i - 1]) cur++;
        else{
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);
    ll ans = 0;
    rep(i, 0, n - 1){
        ans += a[i] - suf[i];
    }
    ans += mx - 1;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}