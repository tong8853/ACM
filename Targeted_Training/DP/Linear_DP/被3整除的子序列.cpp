#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int mod = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int m = s.size();
    s = " " + s;
    ll dp[51][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i, 1, m){
        int num = (s[i] - '0') % 3;
        rep(j, 0, 2){
            dp[i][j] = (dp[i - 1][(j - num + 3) % 3] + dp[i - 1][j]) % mod; //当前这个选和不选分别可以有上一个的两种状态转移
        }
    }
    cout << (dp[m][0] - 1 + mod) % mod << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}