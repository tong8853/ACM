#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int p = 676767677;

void solve(){
    int x, y;
    cin >> x >> y;
    int s = x - y;
    vi a;
    rep(i, 1, x) a.push_back(1);
    rep(i, 1, y) a.push_back(-1);

    ll ans = 0;
    rep(i, 1, abs(s)){
        if(s % i == 0) ans += 1;
    }
    if(s == 0) ans = 1;
    cout << ans % p<< endl;
    rep(i, 0, (int)a.size() - 1) cout << a[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}