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
    int n;
    cin >> n;
    vll a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vll ans;
    ll x = 0;
    ll diff = 0;
    rep(i, 1, n){
        if(i == 1){
            x = a[i];
        }else{
            if(a[i] >= x){
                diff += a[i] - x;
            }else{
                a[i] += diff;
                diff = 0;
                if(a[i] >= x) diff += a[i] - x;
                else{
                    ll dx = (x - a[i] + i - 1) / i;
                    x -= dx;
                    diff += a[i] + (i - 1) * dx - x;
                }
            }
        }
        ans.push_back(x);
    }
    rep(i, 0, n - 1) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}