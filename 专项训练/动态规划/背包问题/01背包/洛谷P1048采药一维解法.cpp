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

int dp[1005];

inline void solve(){
    int T, M;cin >> T >> M;
    rep(i, 1, M){
        //只需要上一行数据和现在这个物品的属性就可以计算出当前行的状态
        int t, val;cin >> t >> val; 
        per(j, T, t) dp[j] = max(dp[j], dp[j - t] + val); //为了防止物品被重复使用
    }
    cout << dp[T] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}