#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define pb push_back    
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 1e5+5;
const ll p = 998244353;

inline void solve(){
    int n, q;cin >> n >> q;
    vi a(n + 1);
    rep(i, 1, n)cin >> a[i];
    int k = log2(n);
    vector<vi> st(n + 1, vi(k + 1));

    rep(i, 1, n) st[i][0] = a[i];
    //预处理采用分治的思想，先枚举区间大小，再枚举区间起点
    rep(i, 1, k){
        rep(j, 1, n - (1 << i) + 1){
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }

    while(q--){
        int l, r;cin >> l >> r;
        int k = log2(r - l + 1);
        cout << max(st[l][k], st[r - (1 << k) + 1][k]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}