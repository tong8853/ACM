#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // 1. 将操作点从大到小排序
    sort(b.rbegin(), b.rend());

    // 2. 插入边界
    vector<int> points;
    points.push_back(n); // b_0
    for (int x : b) {
        points.push_back(x);
    }
    points.push_back(0); // b_{m+1}

    // 计算区间和的辅助函数 (l, r]
    auto get_sum = [&](int l, int r) {
        if (l >= r) return 0LL;
        return pref[r] - pref[l];
    };

    // DP 数组初始化
    // dp[0] 对应偶数状态，dp[1] 对应奇数状态
    ll dp_even = get_sum(points[1], points[0]); // (b_1, n] 区间和
    ll dp_odd = -INF;                           // 非法状态
     for (int k = 1; k <= m; ++k) {
        ll S_k = get_sum(points[k + 1], points[k]); // 区间 (b_{k+1}, b_k] 的和
        
        // 转移
        ll next_even = max(dp_even, dp_odd) + S_k;
        ll next_odd = max(dp_even, dp_odd) - S_k;

        dp_even = next_even;
        dp_odd = next_odd;
    }

    cout << max(dp_even, dp_odd) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}