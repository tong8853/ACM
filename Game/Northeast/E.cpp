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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ca=0,cb=0;
    for(int i=0;i<s.size();i++){
      ca+=s[i]=='1';
    }
    int d=0;
    
    for(int i=1;i<=k;i++){
        d=ca+i;
        int kk=k;
        // string ss=to_string(d);
        int cd=0;
        int tmp=d;
        while(tmp&&kk>=0){
            cd+=tmp&1;
            tmp>>=1;
            kk--;
        }
        if(i==cd)
        {
             int ans=0;
             while(cd)
             {
                ans*=2;
                ans++;
                cd--;
             }
             cout<<ans<<endl;
             return ;
        }
        
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}