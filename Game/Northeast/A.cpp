#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
#define debug(x) cout<<#x<<":"<<x<<endl;
#define debug2(x,y)  cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl; 
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int x,k;
    cin>>x>>k;
    if(k==0||x==1){
        cout<<1<<endl;
        return;
    }

    int upnum=k+1;
    int downnum=0;
    int xx=x;
    int kk=k;
    while(xx>1&&kk>0){
        int tt=sqrt(xx);
        // debug(tt);
        downnum++;
        int res=tt*tt;
        if(res==1) break;
        if(res!=xx&&kk>=1){
            // debug(kk);
         downnum+=kk-1;
        }
        xx=sqrt(xx);
        kk--;
    }
    cout<<upnum+downnum<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while(T--) solve();
    return 0;
}