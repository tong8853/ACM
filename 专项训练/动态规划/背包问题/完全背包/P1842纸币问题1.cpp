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

//https://www.luogu.com.cn/problem/P2842

int dp[N];
inline void solve(){
    memset(dp, 1000000, sizeof(dp)); //初始化为很大的数字，使得在min比较的时候只能取由dp[0]来的数字
    dp[0] = 0;
    int n, W;cin >> n >> W;
    rep(i, 1, n){
        ll w;cin >> w;
        rep(j, w, W){
            dp[j] = min(dp[j], dp[j - w] + 1);
        }
    }
    cout << dp[W] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}