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
    int n, q;
    cin >> n >> q;
    vll a(n+1);
    vector<pair<ll, ll>> b(n+1, {1, 1e9});
    rep(i, 1, n) cin >> a[i];
    bool ok = 0;
    while(q--){
        ll pos, l, r;
        cin >> pos >> l >> r;
        if(l > b[pos].second || r < b[pos].first){
            ok = 1;
        }else{
            b[pos].first = max(b[pos].first, l);
            b[pos].second = min(b[pos].second, r);
        }
    }
    if(ok){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    rep(i, 1, n){
        if(a[i] >= b[i].first && a[i] <= b[i].second) continue;
        else ans += min(abs(a[i] - b[i].first), abs(a[i] - b[i].second));
    }
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