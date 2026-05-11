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

inline void solve(){
    int n;cin >> n;
    vll a(n + 1);
    vll pr(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        pr[i] = pr[i - 1] ^ a[i];
    }

    vll dp(n + 1, 1e18);
    dp[0] = 0;
    auto ask = [&](ll l, ll r){
        return pr[l - 1] ^ pr[r];
    };
    rep(i, 1, n){
        dp[i] = ask(1, i);
        ll mi = dp[i - 1];
        per(j, i - 1, 0){
            dp[i] = min(dp[i], mi + ask(j + 1, i));
            mi = min(mi, dp[j]);
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}