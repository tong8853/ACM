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
    ll a, b;
    cin >> a >> b;
    if(a >= b) swap(a, b);
    if(a != 1 || a == 1 && b == 1){
        cout << "NO" << endl;
        return;
    }

    auto isp = [&](ll x) -> bool{
        if(x == 1) return 0;
        if(x == 2) return 1;
        bool ok = 1;
        rep(i, 2, sqrt(x)){
            if(x % i == 0){
                ok = 0;
            }
        }
        return ok;
    };
    cout << (isp(b) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}