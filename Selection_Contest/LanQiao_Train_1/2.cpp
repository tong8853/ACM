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
    set<int> ss;
    int v = 0;
    int ans = 0;
    while (v != -1) {
        cin >> v;
        if (ss.count(v)) {
            if (!ans) ans = v;
        }
        ss.emplace(v);
    } 
    if (ans) cout << ans << "\n";
    else cout << "None\n";
    // std::cout << ((ans) ? (ans) : ("None")) << "\n";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    // cout<<std::fixed<<std::setprecision(10);
    std::cin.tie(0);
    int t__ = 1;
    cin >> t__;
    while (t__--)
        solve();
    return 0;
}