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
    
    int c[31][31];
    memset(c, 0, sizeof(c));
    rep(i, 0, 30){
        rep(j, 0, 30){
            if(i < j) c[i][j] = 0;
            else if(j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        int ans = 0;
        int d = 0;
        while(n % 2 == 0){
            n /= 2;
            d++;
        }
        rep(i, 0, d - 1){
            rep(j, 1, i + 1){
                if(i + j > k){
                    ans += c[i][j - 1];
                }
            }
        }
        if(d + 1 > k) ans++;
        cout << ans << endl;
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