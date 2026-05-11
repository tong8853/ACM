#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * 解决思路：
 * 定义 b_i = (-a_i - i) mod m。
 * b_i 代表了如果 Hector 想要在最快时间（t=i）到达位置 i，
 * 且他之前从未等待过，他是否会被第 i 个志愿者抓住。
 * 如果 Hector 在位置 i-1 等待了 d 秒，那么他在位置 i 的时刻就是 i + d。
 * 被抓条件：(a_i + i + d) % m == 0  => d % m == (-a_i - i) % m = b_i。
 * * 实际上，这就是一个区间覆盖问题。Hector 可以选择 d >= 0。
 * 如果存在一段连续的志愿者，他们的 b_i 刚好封锁了所有可能的等待时间 d，
 * 那么 Hector 就无法通过。
 */

void solve(){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // 计算标准化后的封锁时间点
        b[i] = (m - (a[i] + (i + 1)) % m) % m;
    }

    // 排序 b 数组，检查是否存在连续的封锁点
    sort(b.begin(), b.end());

    // 唯一能让 Hector 无法通过的情况是：
    // 这些封锁点 b_i 过于密集，以至于无论他怎么等（d 是多少），
    // 都会在进入某个位置时撞上某人的 0 时刻。
    // 经过数学简化，若 count(b_i == x) 在某个范围内超过了空隙，则失败。
    // 但更简单的结论是： Hector 总是能通过，除非封锁点的数量和分布达到了 m 的限制。
    // 在这道题的约束下，Hector 只有在被“逼入死角”时才会输。
    
    // 实际上，本题 Hector 拥有极其灵活的移动能力（左移、右移、原地）。
    // 只要 m > n，他永远可以找到一个时间空隙通过。
    // 因为他最多面对 n 个志愿者，每个志愿者只在模 m 的一个时间点封锁。
    // 如果 m > n，总有一个时刻 t (mod m) 是所有志愿者都不在 0 状态的。
    
    if (m > n) {
        cout << "YES" << endl;
    } else {
        // 如果 m <= n，理论上可能被封锁。
        // 检查是否存在一个时间点，使得 Hector 无论如何等待都无法避开。
        // 统计每个标准化封锁点出现的次数
        bool possible = true;
        int current_streak = 1;
        
        // 检查 b 数组中是否有重复或者连续的封锁
        // 在这道题的逻辑中，如果 m <= n，我们需要看是否所有的 mod m 被覆盖
        vector<int> counts(m, 0);
        for(long long x : b) counts[x]++;
        
        for(int i=0; i<m; ++i) {
            if(counts[i] == 0) {
                possible = true; 
                break;
            }
            possible = false;
        }
        
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}