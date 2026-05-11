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

const int N = 2E6;
int cnt = 0;
int primes[N], st[N];

void getPrime() {
    st[0] = st[1] = true;
    for (int i = 2; i < N; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; j < cnt && primes[j] <= N / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    int l, r; cin >> l >> r;
    if (2 < l || 2 > r) {
        cout << 0;
        return;
    }
    int ans = 0;
    rep(x, max(3LL, l), r) {
        rep(y, x + 1, r) {
            if (!st[x] && !st[y] && !st[2 * x + y] && !st[2 * y + x] && !st[x * y + 2]) ans++;
        }
    }
    cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    // cout<<std::fixed<<std::setprecision(10);
    std::cin.tie(0);
    int t__ = 1;
    getPrime();
    //cin >> t__;
    while (t__--)
        solve();
    return 0;
}