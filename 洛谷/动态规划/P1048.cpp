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
const int M = 1e6+5;
const ll INF = 1e15;       // 注意判断 INF 具体的可能值

ll dp[1005][1005]; //前i株药，时间j以内的最大价值

inline void solve(){
    int T, m;//t时间，m物品数量
    cin >> T >> m;
    rep(i, 1, m){
        int t, val;cin >> t >> val;
        rep(j, 0, T){
            if(j < t){
                dp[i][j] = dp[i - 1][j]; //不选
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + val);//选还是不选，取max
            }
        }
    }
    cout << dp[m][T] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}