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
    int n;cin >> n;
    ll res_a = 0, res_b = 1; // 存储累加结果的分子和分母

    rep(i, 1, n) {
        ll x, y;
        scanf("%lld/%lld", &x, &y);
        
        // 1. 通分相加：res_a/res_b + x/y = (res_a*y + x*res_b) / (res_b*y)
        ll next_a = res_a * y + x * res_b;
        ll next_b = res_b * y;
        
        // 2. 核心步骤：每一步都立刻约分，防止后续乘法溢出
        ll common = gcd(next_a, next_b);
        res_a = next_a / common;
        res_b = next_b / common;
    }

    // 3. 输出逻辑
    ll zheng = res_a / res_b;      // 整数部分
    ll fenzi = res_a % res_b;      // 剩余分子部分

    if (zheng == 0 && fenzi == 0) {
        printf("0\n");
    } else {
        if (zheng != 0) {
            cout << zheng;
            if (fenzi != 0) cout << " ";
        }
        if (fenzi != 0) {
            cout << fenzi << '/' << res_b;
        }
    }
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--)solve();
}