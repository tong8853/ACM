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
    int n, a, b;
    int f = 0;
    cin >> n >> a >> b;
    auto dfs = [&](auto dfs, int len, int cur) -> void {
        if (len > n) {
            if (cur >= a && cur <= b) {
                cout << cur << '\n';
                f = true;
            }
            return;
        }
        rep(d, 0, 9) {
            if (len == 1 && d == 0) continue; 
            int nxt = cur * 10 + d;
            if (nxt % len == 0)
                dfs(dfs, len + 1, nxt);
        }
    };
    dfs(dfs, 1, 0);
    if (!f) cout << "No Solution\n";
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