#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
using ll = long long;
using vi = vector<int>;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int s = 0;
    rep(i, 0, n - 1) {
        cin >> a[i];
        s ^= a[i];
    }

    if (s == 0) {
        cout << "YES" << endl;
        return;
    }

    int cnt = 0, cur = 0;
    rep(i, 0, n - 1) {
        cur ^= a[i];
        if (cur == s) {
            cnt++;
            cur = 0;
        }
    }

    // 当 s != 0 时，必须能分成奇数个 s 才能保持总异或和为 s
    // 只要 cnt >= 3 即可满足题目要求
    if (cnt >= 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}