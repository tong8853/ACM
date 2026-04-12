#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5;
const ll p = 998244353;

ll f[N], inv[N];

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1; 
    }
    return res;
}
ll C(int n, int m){
    if(m < 0 || m > n) return 0;
    return f[n] * inv[m] % p * inv[n - m] % p;
}


inline void solve(){
    int n; cin >> n;
    string s(n + 1, ' ');
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    
    rep(i, 1, n){
        cin >> s[i];
        if(s[i] == 'j') cnt1++;
        else if(s[i] == 'o') cnt2++;
        else cnt3++;
    }
    int tar1 = (n + 1) / 2;
    int tar2 = n / 2;

    int xu1 = tar1 - cnt1;
    int xu2 = tar2 - cnt2;

    if(xu1 < 0 || xu2 < 0){
        cout << 0 << endl;
        return;
    }
    ll ans = C(cnt3, xu1); 
    ans = ans * f[tar1] % p * f[tar2] % p;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    f[0] = 1;
    rep(i, 1, N){
        f[i] = f[i - 1] * i % p;
    }
    inv[N - 1] = qpow(f[N - 1], p - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % p;
    int T = 1;//cin >> T;
    while(T--)solve();
}