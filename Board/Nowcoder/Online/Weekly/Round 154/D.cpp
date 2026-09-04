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
    vi a(2 * n);
    rep(k, 1, 2){
        rep(i, 0, n - 1){
            if(s[i] == '0') a.push_back(0);
            else a.push_back(1);
        }
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l > r) r += n;
        if(r == 2 * n - 1){
            a[l]++;
        }else{
            a[l]++;
            a[r + 1]--;
        }
    }
    rep(i, 1, 2 * n - 1){
        a[i] += a[i - 1];
    }
    rep(i, 0, n - 1){
        a[i] += a[i + n];
    }
    ll ans = 0;
    rep(i, 0, n - 1){
        if(i != n - 1){
            if((a[i] + a[i + 1]) % 2) ans++;
        }else{
            if((a[n - 1] + a[0]) % 2) ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}