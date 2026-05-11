#include <bits/stdc++.h>
using namespace std;

// 定义全局变量
const int MAXN = 2e5 + 7;
int n;
vector<int> v;
bool vis[MAXN]; // 全局布尔数组用于计算 MEX

int solve(int l, int r) {
    // 每次计算前，只重置当前范围内可能用到的 vis 标记
    // 这样比 memset(vis, 0, sizeof(vis)) 快得多
    for (int i = 0; i <= n; i++) vis[i] = false;

    while (l >= 0 && r < 2 * n && v[l] == v[r]) {
        if (v[l] <= n) vis[v[l]] = true;
        l--; r++;
    }

    // 线性查找 MEX
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) return i;
    }
    return n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        v.assign(2 * n, 0); // 更新全局 vector 大小并清零
        
        int p1 = -1, p2 = -1;
        for (int i = 0; i < 2 * n; i++) {
            cin >> v[i];
            if (v[i] == 0) {
                if (p1 == -1) p1 = i;
                else p2 = i;
            }
        }

        // 计算三种情况的最大值
        int ans = max({
            solve(p1, p1), 
            solve(p2, p2), 
            solve((p1 + p2) / 2, (p1 + p2 + 1) / 2)
        });

        cout << ans << "\n";
    }
    return 0;
}