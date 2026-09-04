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
    string s;
    cin >> s;
    vi a(n), dif(n);
    rep(i, 0, n - 1){
        if(s[i] == '0') a[i] = 0;
        else a[i] = 1;
    }
    rep(i, 0, n - 1){
        dif[i] = abs(a[i] - a[(i + 1) % n]);
    }

    ll ans = 0;
    rep(i, 0, n - 1){
        if(dif[i] == 1) ans++;
    }
    while(q--){
        int l, r;
        cin >> l >>r;
        l = (l - 1 + n) % n;
        ans -= diff[l];
        ans -= diff[r];
        diff[l] ^= 1;
        diff[r] ^= 1;
        ans += diff[l];
        ans += diff[r];
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