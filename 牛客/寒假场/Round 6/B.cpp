#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

ll f[M], inv[M];

ll qpow(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void pre(){
    f[0] = 1;
    rep(i, 1, M - 1) f[i] = f[i - 1] * i % p;
    inv[M - 1] = qpow(f[M - 1], p - 2);
    per(i, M - 2, 0) inv[i] = inv[i + 1] * (i + 1) % p;
}

ll C(int n, int m){
    if(m < 0 || m > n) return 0;
    return f[n] * inv[m] % p * inv[n - m] % p;
}

inline void solve(){
    int n, L, t, R;cin >> n >> L >> t;
    R = n - L;
    if(t == 0){
        if(R == 0 || L == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    if(L == 0 || R == 0){
        cout << 0 << endl; 
        return;
    }

    ll ans = 0;
    //t + 1 个段
    //左边开始
    int kL1 = (t + 2) / 2;
    int kR1 = (t + 1) / 2;
    if(L >= kL1 && R >= kR1){
        ans = (ans + C(L - 1, kL1 - 1) * C(R - 1, kR1 - 1)) % p;
    }
    //右边开始
    int kL2 = (t + 1) / 2;
    int kR2 = (t + 2) / 2;
    if(L >= kL2 && R >= kR2){
        ans = (ans + C(R - 1, kR2 - 1) * C(L - 1, kL2 - 1)) % p;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    pre();
    int T = 1;cin >> T;
    while(T--)solve();
}