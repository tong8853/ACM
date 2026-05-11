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
    int a, b; cin >> a >> b;
    int mx = -1;
    vector<int> ans;
    auto get = [&](int x)->int {
        int cnt = 0;
        while (x >= 10) {
            int res = 1;
            while (x) {
                res *= (x % 10);
                x /= 10;
            }
            x = res;
            cnt++;
        }
        return cnt;
    };
    rep(i, a, b) {
        int t = get(i);
        if (t > mx) {
            mx = t;
            ans.clear();
            ans.push_back(i);
        }
        else if (t == mx) {
            ans.push_back(i);
        }
    }
    cout << mx << "\n";
    rep(i, 0, ans.size() - 1) {
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