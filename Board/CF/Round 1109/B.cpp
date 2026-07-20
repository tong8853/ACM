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
    rep(i, 1, n - 1){
        if(a[i] >= i){
            a[i + 1] += a[i] - i;
            a[i] = i;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    if(a[n] < n) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}