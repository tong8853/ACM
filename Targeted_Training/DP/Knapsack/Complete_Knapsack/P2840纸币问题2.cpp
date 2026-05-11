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
const ll p = 1e9 + 7;

//https://www.luogu.com.cn/problem/P2840

inline void solve(){
    int n, w;cin >> n >> w;
    vi a(n + 1);
    read(a, 1, n);
    vll dp(w + 1, 0); //dp[i] 表示凑出金额i的方案数量
    dp[0] = 1;
    rep(i, 1, w) rep(j, 1, n){
        if(i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % p;
    }
    cout << dp[w] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}
