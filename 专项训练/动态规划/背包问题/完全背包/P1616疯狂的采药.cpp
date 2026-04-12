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

const int N = 1e7+5;
const ll p = 998244353;

//https://www.luogu.com.cn/problem/P1616


ll dp[N];
inline void solve(){
    ll T, m;cin >> T >> m;
    rep(i, 1, m){
        ll t, v;cin >> t >> v;
        rep(j, t, T){
            dp[j] = max(dp[j], dp[j - t] + v);
        }
    }
    cout << dp[T] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}