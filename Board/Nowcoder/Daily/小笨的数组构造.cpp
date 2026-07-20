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
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 1) {
        if (x == y) {
            cout << "YES\n" << x << '\n';
            return;
        }
        cout << "NO\n";
        return;
    }
    if (y & ~x) {
        cout << "NO\n";
        return;
    }
    if (!(n & 1) && x == y) {
        int lb = x & -x;
        if (lb == x) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n" << lb << ' ' << (x ^ lb);
        for (int i = 2; i < n; i++) {
            cout << ' ' << x;
        }
        cout << '\n';
        return;
    }
    cout << "YES\n" << (n & 1 ? y : x ^ y);
    for (int i = 1; i < n; i++) {
        cout << ' ' << x;
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}