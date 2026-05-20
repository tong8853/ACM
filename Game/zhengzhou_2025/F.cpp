#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
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
    queue<int>q,ql,qr;
    
    q.push(0);
    map<int,int>vis;
    int mnl=10000;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int x=cur/hs;
        int y=cur%hs;

        for(int i=0;i<4;i++){
            int px=x+dx[i];
            int py=y+dy[i];
            if(px<0||px>=n||py<0||py>=m) continue;
            int nw=px*hs+py;
            vis[nw]=1;
            if(vis[nw]) continue;
            if(g[px][py]=='#') continue;
            q.push(nw);
            int tt=abs(px-n+1)+abs(py-m+1);
            mnl=min(mnl,tt);
        }
    }


    qr.push((n-1)*hs+m-1);
    int mxr=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int x=cur/hs;
        int y=cur%hs;

        for(int i=0;i<4;i++){
            int px=x+dx[i];
            int py=y+dy[i];
            if(px<0||px>=n||py<0||py>=m) continue;
            int nw=px*hs+py;
            vis[nw]=1;
            if(vis[nw]) continue;
            if(g[px][py]=='#') continue;
            q.push(nw);
            int tt=abs(px-(n-1))+abs(py-(m-1));
            mxr=max(mxr,tt);
        }
    }

    int ans=abs(mxr-mnl);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
