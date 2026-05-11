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
    vll a(n + 1), b(n + 1);
    rep(i, 1, n){
        ll x, y;
        scanf("%lld/%lld", &x, &y);
        a[i] = x, b[i] = y;
    }
    ll lcmx = 1;
    rep(i, 1, n){
        lcmx = lcm(lcmx, b[i]);
    }
    rep(i, 1, n){
        a[i] *= (lcmx) / b[i];
    }
    ll sum = 0;
    rep(i, 1, n) sum += a[i];
    ll zheng = sum / lcmx;
    ll fenzi = sum % lcmx;
    if(zheng == 0 && fenzi == 0){
        cout << 0;
        return;
    } 
    if(zheng){
        cout << zheng;
        if(fenzi) cout << " ";
    }
    ll gcdx = gcd(fenzi, lcmx);
    if(fenzi)cout << fenzi / gcdx << '/' << lcmx / gcdx;
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--)solve();
}