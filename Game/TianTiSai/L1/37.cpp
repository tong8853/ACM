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
    double a, b;
    cin >> a >> b;
    double ans = a / b;
    if(b < 0){
        if(b == 0) cout << a << '/' << '(' << b << ")=" << "Error";
        else cout << a << '/' << '(' << b << ")=" << fixed << setprecision(2) <<ans;
    }else{
        if(b == 0) cout << a << '/' << b << "=" << "Error";
        else cout << a << '/' <<  b << "=" << fixed << setprecision(2) << ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}