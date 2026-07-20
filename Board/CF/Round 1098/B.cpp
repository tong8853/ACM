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
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if(n <= 3){
        cout << 1 << endl;
        return;
    }

    ll L = -1;
    if(x1 < x2){
        L = min(n - x2 + x1, x2 - x1);
    }else L = min(n - x1 + x2, x1 - x2);
    cout << k + L << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}