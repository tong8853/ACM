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
    int n, d; 
    cin >> n >> d;
    vector<int> p(n), c(n);
    rep(i, 0, n - 1) cin >> p[i];
    rep(i, 0, n - 1) cin >> c[i];
    sort(c.begin(), c.end());
    // cost, 商品下标, 代金券下标
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    // 每个商品先放入“用最大代金券购买”的那一次
    rep(i, 0, n - 1)
    {
        q.push({p[i] - c[n - 1], i, n - 1});
    }
    int cnt = 0;
    while (!q.empty())
    {
        auto t = q.top();
        if (t[0] > d) break;
        q.pop();
        int cost = t[0], id = t[1], idx = t[2];
        d -= cost;
        cnt++;
        if (idx - 1 >= 0)
        {
            int nxt = idx - 1;
            q.push({p[id] - c[nxt], id, nxt});
        }
    }
    cout << cnt << ' ' << d << '\n';
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