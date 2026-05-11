#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 p, x, k;
    std::cin >> p >> x >> k;
    
    std::map<i64, int> cnt;
    auto factor = [&](i64 n, int c) {
        for (i64 x = 2; x * x <= n; x++) {
            while (n % x == 0) {
                cnt[x] += c;
                n /= x;
            }
        }
        if (n > 1) {
            cnt[n] += c;
        }
    };
    factor(k, 100);
    factor(p, 1);
    
    std::vector a(cnt.rbegin(), cnt.rend());
    i64 ans = 0;
    auto dfs = [&](auto &&self, int i, i64 n) {
        if (i == a.size()) {
            ans++;
            return;
        }
        for (int j = 0; j <= a[i].second; j++, n *= a[i].first) {
            self(self, i + 1, n);
            if (n > x / a[i].first) {
                break;
            }
        }
    };
    dfs(dfs, 0, 1);
    
    std::cout << ans << "\n";
    
    return 0;
}
