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
    int n, k; 
    cin >> n >> k;  
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    multiset<int> s;
    rep(i, 0, k - 1) s.insert(a[i]);
    vector<int> ans;
    ans.push_back(*prev(s.end()));  
    rep(i, k, n - 1)
    {
        s.erase(s.find(a[i - k]));  
        s.insert(a[i]);             
        ans.push_back(*prev(s.end()));
    }
    rep(i, 0, (int)ans.size() - 1)
    {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
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