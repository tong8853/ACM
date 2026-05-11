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
      ca+=(s[i]=='1');
    }
    int d=0;
    // int ans=0;
    // debug(ca)
    // vector<pair<int ,string>>rr;
    string ans="999999999999999999999";
    for(int i=0;i<=k;i++){
        string sa=s;
        d=ca+i;
        // debug(d);
        string sd="";
        int dd=d;
        //10
        while(dd){
            int tmp=dd&1;
            // debug(tmp);
            sd+=(tmp+'0');
            dd>>=1;
        }
        string sds=sd.substr(0,k);
        sd=sds;
        reverse(sd.begin(),sd.end());
        // debug(sd);
        string sc=sa+sd;
        int nc=0;
        for(char cc:sc){
           nc+=(cc=='1');
        }
        // debug(sc);
        // debug(nc);
        // debug(d)
        if(nc==d){
            // debug(sc);
            if(sc.size()<=(sa.size()+k)){
               // debug(sd.size());
                int r1=sd.size();
            for(int p=1;p<=(k)-r1;p++) {
                sd="0"+sd;
            }
            ans=min(ans,sd);
            // cout<<sd<<endl;
            // int val=0,bs=1;
            // while(sd.size()){
            //     if(sd.back()=='1') val=val+bs;
            //     bs<<=1;
            //     sd.pop_back(); 
            // }
            // rr.push_back({val,sd});
            // return;
          }
        }
        
    }
    // sort(rr.begin(),rr.end());
    // if(rr.size()){
    //     cout<<rr[0].second<<endl;
    // }else
    if(ans!="999999999999999999999")cout<<ans<<endl;
    else cout<<"None"<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}