#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

// 求最大公约数 (C++17 以后可以使用 std::gcd)
ll get_gcd(ll a, ll b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

void solve(){
    int n;
    if (!(cin >> n)) return;
    vi p(n);
    rep(i, 0, n - 1) cin >> p[i];

    ll ans = 0;
    // 关键结论：好数组只能由两个相邻元素组成
    // 且满足 |p[i] - p[i+1]| == gcd(p[i], p[i+1])
    rep(i, 0, n - 2) {
        int a = p[i];
        int b = p[i + 1];
        if (abs(a - b) == get_gcd(a, b)) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T; // 图片显示有多个 test cases
    while(T--) solve();
    return 0;
}