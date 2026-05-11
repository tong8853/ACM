#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int,2>
#define endl "\n"

const int INF = 1e18;

void solve() {
    int n;cin >> n;
    vector<int> a(n+9);
    for (int i = 1; i <= n; i++) cin >> a[i];
    //凝聚力 = (a_i - a_j) - |i - j|

    //最小值在最大值左边
    //最大化(a_i - i) - (a_j - j)
    int ans = 0;
    int pre = INF;
    for (int i = 1; i <= n; i++) {
        pre = min(pre, a[i]-i);
        ans = max(ans, a[i]-i-pre);
    }

    reverse(a.begin()+1, a.begin()+n+1);
    //最小值在最大值右边
    //最大化(a_i + i) - (a_j + j)
    pre = INF;
    for (int i = 1; i <= n; i++) {
        pre = min(pre, a[i]-i);
        ans = max(ans, a[i]-i-pre);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}