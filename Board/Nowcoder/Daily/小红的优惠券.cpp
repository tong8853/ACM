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
    int n, m;
    cin >> n >> m;
    vi a(m + 1), b(m + 1);
    rep(i, 1, m) cin >> a[i] >> b[i];
    int c = 0;
    rep(i, 1, m){
        if(n >= a[i]){
            c = max(c, b[i]);           
        }
    }
    cout << n - c << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}