#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;


void solve(){
    double x, y, z;
    cin>>x>>y>>z;
    
    double s = max(2.0, x+0.4);
    double t = x*y + max(2.0-x, 0.4)*z;
    double v = t/s;

    cout<<(int)v<<endl;
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
    return 0;
}