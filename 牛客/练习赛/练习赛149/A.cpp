#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        sort(a.begin(), a.end());
        
        ll ans = 0;
        int prev = a[0];  // 上一个实际颜色
        
        for (int i = 1; i < n; ++i) {
            if (a[i] <= prev) {
                ans += prev + 1 - a[i];  // 需要增加的次数
                a[i] = prev + 1;        // 更新为合法值
            }
            prev = a[i];
        }
        
        cout << ans << '\n';
    }
    return 0;
}