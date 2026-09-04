#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 31;
int h[6];
ll dp[N][N][N][N][N];

void solve(){
    
    int k;
    while(cin >> k && k != 0){
        memset(dp, 0, sizeof(dp));
        memset(h, 0, sizeof(h));
        rep(i, 1, k) cin >> h[i];
        dp[0][0][0][0][0] = 1;
        rep(a, 0, h[1]){
            rep(b, 0, h[2]){
                rep(c, 0, h[3]){
                    rep(d, 0, h[4]){
                        rep(e, 0, h[5]){
                            ll delta = 0;
                            if(a >= 1 && a - 1 >= b) delta += dp[a - 1][b][c][d][e];
                            if(b >= 1 && b - 1 >= c) delta += dp[a][b - 1][c][d][e];
                            if(c >= 1 && c - 1 >= d) delta += dp[a][b][c - 1][d][e];
                            if(d >= 1 && d - 1 >= e) delta += dp[a][b][c][d  -1][e];
                            if(e >= 1) delta += dp[a][b][c][d][e  -1];
                            dp[a][b][c][d][e] += delta;
                        }
                    }
                }
            }
        }
        cout << dp[h[1]][h[2]][h[3]][h[4]][h[5]] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}