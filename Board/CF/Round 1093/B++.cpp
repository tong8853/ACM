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
    int n; ll m;
    cin >> n >> m;
    ll r = -1, pre = -1;
    bool ok = true;

    rep(i, 1, n) {
        ll a; cin >> a;
        if(!ok) continue;

        // b 为当前位置对应的“虚拟出发时间”禁区点
        ll b = (m - (a + i) % m) % m;

        if(i == 1) {
            r = b;
        } else {
            // 检查 b 是否能接在上一段禁区 [ (pre-1)%m, r ] 之后
            ll l_chk = (pre - 1 + m) % m;
            bool in = (l_chk <= r) ? (b >= l_chk && b <= r) : (b >= l_chk || b <= r);
            
            if(!in) r = b; // 如果不连续，禁区重置，Hector 找到了缝隙
        }
        pre = b;
        
        // 区间长度 len = (右端点 - 左端点 + m) % m + 1
        if((r - b + m) % m + 1 >= m) ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}