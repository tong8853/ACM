#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n;
string s;
int dp[1000005][26];

void solve(){
    cin >> n >> s;
    rep(i, 1, n){
        int minx = INT_MAX;
        rep(j, 0, 25){
            minx = min(minx, dp[i - 1][j]);
            dp[i][j] = minx + abs(j - (s[i - 1] - 'A'));
        }
    }
    cout << *min_element(dp[n], dp[n] + 26) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}