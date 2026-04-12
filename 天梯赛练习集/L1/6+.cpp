#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    ll n; cin >> n;
    ll best_l = 0, max_cnt = 0;

    // 外层枚举起始因子，由于题目 N < 2^31，sqrt(N) 约为 46340
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0, tmp = n, j = i;
        while (tmp % j == 0) {
            tmp /= j++;
            cnt++;
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            best_l = i;
        }
    }

    if (!max_cnt) { // 处理质数情况
        cout << "1\n" << n << endl;
    } else {
        cout << max_cnt << endl;
        for (int i = 0; i < max_cnt; i++)
            cout << (i ? "*" : "") << best_l + i;
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}