#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define debug(x) std::cout << #x << " : " << x << "\n";
#define debug2(x,y) std::cout << #x << " : " << x << " " << #y << " : " << y << "\n";

void solve()
{
    int n; cin >> n;

    auto qpow = [&](int a, int b, int lim) -> int {
        int res = 1;
        while (b) {
            if (b & 1) {
                int t = res * a;
                if (t > lim) return lim + 1;
                res = t;
            }
            b >>= 1;
            if (b) {
                int t = a * a;
                if (t > lim) a = lim + 1;
                else a = t;
                if (a > lim) a = lim + 1;
            }
        }
        return res;
    };

    rep2(k, 30, 1) {
        int sum = 0;
        rep(m, 1, n) {
            int tmp = qpow(m, k, n - sum);
            if (tmp > n - sum) break;
            sum += tmp;
            if (sum == n) {
                rep(i, 1, m) {
                    cout << i << "^" << k;
                    if (i != m) cout << "+";
                }
                return;
            }
        }
    }
    cout << "Impossible for " << n << ".";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    // cout<<std::fixed<<std::setprecision(10);
    std::cin.tie(0);
    int t__ = 1;
    //cin >> t__;
    while (t__--)
        solve();
    return 0;
}