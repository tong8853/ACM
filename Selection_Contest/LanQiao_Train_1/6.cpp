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
    auto is_sqr = [&](int x) -> int {
        if (x == 0) return true;
        int l = 1, r = 50000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid == x / mid && mid * mid == x) return true;
            if (mid <= x / mid) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    };
    auto is_cub = [&](int x) -> int {
        if (x == 0) return true;
        int l = 1, r = 2000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid == x / mid / mid && mid * mid * mid == x) return true;
            if (mid <= x / mid / mid) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    };

    while (n--) {
        int z; cin >> z;
        int ok2 = false, ok3 = false;
        int tmp = z;
        if (z % 3 == 0) {
            tmp = z / 3;
            if (is_cub(tmp)) ok3 = true;
        }

        if (z % 2 == 0) {
            tmp = z / 2;
            if (is_sqr(tmp)) ok2 = true;
        }

        if (ok3) cout << z << " is a triple flower\n";
        else if (ok2) cout << z << " is a double flower\n";
        else cout << z << " is " << z << "\n";
    }
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