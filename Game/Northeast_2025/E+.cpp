#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)

void solve() {
    int n, k;
    cin >> n >> k;
    string a; cin >> a;
    
    int ca = 0;
    for (char c : a) if (c == '1') ca++;
    
    int ans = -1;
    int mod = (1 << k);

    // 枚举 B 中 1 的个数 j，范围是 0 到 k
    rep(j, 0, k) {
        // 计算候选的 B，即题目中的 D
        int b = (ca + j) % mod;
        
        // 校验这个数值 b 的实际 1 的个数是否等于枚举的 j
        if (__builtin_popcount(b) == j) {
            // 找到符合条件的 B 后，维护最小值（题目要求最小的 B）
            if (ans == -1 || b < ans) ans = b;
        }
    }

    if (ans == -1) {
        cout << "None" << endl;
    } else {
        // 直接按位输出 k 位二进制，高位补 0
        rep2(i, k - 1, 0) {
            cout << ((ans >> i) & 1);
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}