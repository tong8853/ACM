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
    vi a(n);
    rep(i, 0, n-1) cin >> a[i];

    vi r(n);
    rep(i, 0, n-1){
        r[i] = (m - a[i] % m) % m;
    }

    if(m == 2){
        bool found = false;
        rep(i, 0, n-2){
            if(r[i] == r[i+1]){
                found = true;
                break;
            }
        }
        if(found){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        cout << "YES" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}