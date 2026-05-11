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
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int k;
    cin >> k;
    vi pre(n + 1);
    rep(i, 2, n){
        if(a[i] - a[i - 1] > 0) pre[i] = a[i] - a[i - 1];
    }
    rep(i, 2, n) pre[i] += pre[i - 1];
    rep(i, 1, m){
        int l, r;
        cin >> l >> r;
        ll dx = 0;
        dx += pre[r] - pre[l];
        cout << dx + k << endl;
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