#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int a[10][10];
void solve(){
    
    // a[0][0] = 1;
    // a[0][1] = 1;
    // a[1][0] = 1;
    // a[1][1] = 1;

    // auto f = [&](auto self, int x, int y)->int{
    //     if(a[x][y]) return a[x][y];
        
    //     if((x > 0 && y > 1 && self(self, x - 1, y - 2) == 1) || (x > 1 && y > 0 && self(self, x - 2, y - 1) == 1)) return a[x][y] = 2;

    //     return a[x][y] = 1;
    // };
    // rep(i, 0, 9){
    //     rep(j, 0, 9){
    //         f(f, i, j);
    //     }
    // }
    // rep(i, 1, 9){
    //     rep(j, 1, 9){
    //         if(a[i][j] == 1) cout << 'P';
    //         else cout << '.';
    //     }
    //     cout << endl;
    // }

    ll a, b;
    cin >> a >> b;
    ll minx = min(a, b);
    if(minx % 3 == 0 || a % 3 == 1 && a == b) cout << "niumei" << endl;
    else cout << "niuniu" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}