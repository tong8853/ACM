#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i]; // 前缀异或
    }

    // dp[i] 表示覆盖前 i 个元素的最小代价
    // 初始化为一个很大的值
    vector<long long> dp(n + 1, 2e18); 
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            // 枚举最后一个区间的起点 j+1，终点 i
            // 该区间的代价是 s[i] ^ s[j]
            dp[i] = min(dp[i], dp[j] + (s[i] ^ s[j]));
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}