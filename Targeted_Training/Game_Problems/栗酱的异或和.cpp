#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int sum = 0;
    rep(i, 1, n) sum ^= a[i];
    //必胜策略是：找到某堆石子数 a_i，使得 (total_xor ^ a_i) < a_i，然后从该堆取走 a_i - (total_xor ^ a_i) 个石子，使剩余所有堆的异或和变为 0。
    cout << ((sum ^ a[k]) < a[k] ? "Yes" : "No") << endl;
    //等价于 a_k 在 total 的最高位1的对应位次上为 1
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}