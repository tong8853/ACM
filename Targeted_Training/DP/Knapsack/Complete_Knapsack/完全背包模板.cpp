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

//https://www.nowcoder.com/practice/deda4293d9b24ce1aeaf1813c88b8c25?tpId=386&tqId=11267007&channelPut=tracker1

inline void solve(){
    int n, m;cin >> n >> m;
    vi dp(1005);
    rep(i, 1, n){
        int w, v;cin >> w >> v;
        rep(j, w, m){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[m] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}