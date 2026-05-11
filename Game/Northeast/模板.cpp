#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout<<#x<<":"<<x<<endl;
#define debug2(x,y)  cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl; 
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    double n, m;
    cin >> n >> m;
    cout << fixed <<setprecision(2) << 0.6 * n + m << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}