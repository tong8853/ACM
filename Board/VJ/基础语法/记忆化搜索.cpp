#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    ll a, b, c;
    ll dp[22][22][22];
    memset(dp, -1, sizeof(dp));

    auto w = [&](auto self, ll a, ll b, ll c) -> ll{
        if(a<=0 || b<=0 || c<=0) return 1;
        if(a>20 || b>20 || c>20) return self(self, 20, 20, 20);
        if(dp[a][b][c] != -1) return dp[a][b][c];
        if (a < b && b < c) dp[a][b][c] = self(self, a, b, c - 1) + self(self, a, b - 1, c - 1) - self(self, a, b - 1, c);
        else dp[a][b][c] = self(self, a - 1, b, c) + self(self, a - 1, b - 1, c) + self(self, a - 1, b, c - 1) - self(self, a - 1, b - 1, c - 1);
        return dp[a][b][c];
    };

    while(cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1)){
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(w, a, b, c));
    }
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}