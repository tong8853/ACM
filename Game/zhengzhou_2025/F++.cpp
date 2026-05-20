#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define debug(x) cout<<#x<<":"<<x<<endl;

using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int hs=10000;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    queue<int>q;
    
    q.push(0);

    unordered_map<int,int>vis;
    vector<int>L,R;
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int x=cur/hs;
        int y=cur%hs;
        
        bool bian=false;
        for(int i=0;i<4;i++){
            int px=x+dx[i];
            int py=y+dy[i];
            if(px==(n-1)&&(py==(m-1))){
                cout<<0<<endl;
                return;
            }
            
            if(px<0||px>=n||py<0||py>=m) continue;
            int nw=px*hs+py;

            if(g[px][py]=='#') {
                bian=true;
                continue;
            }

            if(vis[nw]) continue;
            vis[nw]=1;
            q.push(nw);
        }

        if(bian){
             L.push_back(cur);
        }
    }


    q.push((n-1)*hs+(m-1));
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int x=cur/hs;
        int y=cur%hs;
        
        bool bian=false;
        for(int i=0;i<4;i++){
            int px=x+dx[i];
            int py=y+dy[i];
            if(px<0||px>=n||py<0||py>=m) continue;
            int nw=px*hs+py;
            if(g[px][py]=='#') {
                bian=true;
                continue;
            }

            if(vis[nw]) continue;
            vis[nw]=1;
            q.push(nw);
        }

        if(bian){
            R.push_back(cur);
        }
    }
    
    int ans=10000;
    // debug(L.size());
    // debug(R.size());
    L.erase(unique(L.begin(),L.end()),L.end());
    R.erase(unique(R.begin(),R.end()),R.end());

    for(auto itl:L){
         int x1=itl/hs;
         int y1=itl%hs;
        for(auto itr:R){
          int x2=itr/hs;
          int y2=itr%hs;
        //   debug(x2);
        //   debug(y2);
          int len=abs(x1-x2)+abs(y1-y2);
          ans=min(ans,len-1);
        }
    }
    if(L.size()==0) cout<<0<<endl;
    else {
        if(ans==10000) cout<<0<<endl;
        else        cout<<ans<<endl;
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
