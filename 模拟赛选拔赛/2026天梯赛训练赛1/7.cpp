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
    int n, m; cin >> n >> m;
    vector<int> fa(m + 1);
    rep(i, 1, m) fa[i] = i;
    auto find = [&](auto self, int x) -> int {
        if (fa[x] == x) return x;
        return fa[x] = self(self, fa[x]);
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x), y = find(find, y);
        if (x != y) fa[x] = y;
    };
    rep(i, 1, n) {
        int k; cin >> k;
        vector<int> a(k + 1);
        rep(j, 1, k) cin >> a[j];
        rep(j, 2, k) merge(a[1], a[j]);
    }
    vector<int> mn(m + 1, (int)4e18);
    rep(i, 1, m) {
        int f = find(find, i);
        mn[f] = min(mn[f], i);
    }
    vector<int> ans;
    rep(i, 1, m) {
        if (fa[i] == i && mn[i] != (int)4e18) ans.push_back(mn[i]);
    }
    sort(ans.begin(), ans.end());
    rep(i, 0, (int)ans.size() - 1) {
        if (i) cout << " ";
        cout << ans[i];
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