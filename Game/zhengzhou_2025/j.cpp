#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define debug(x) cout<<#x<<":"<<x<<endl;
#define int long long
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int fa[1000002]={};

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    int xx = find(x);
    int yy = find(y);
    fa[xx] = yy;
}

void solve(){
   int n,m;
   cin>>n>>m;
   int sum=0;
   for(int i=1;i<=n;i++){
      fa[i]=i;
   }
   
   int cha=0;
   for(int i=1;i<=m;i++){
         int u,v;
         cin>>u>>v;
         if(find(u)==find(v)) cha++;
         merge(u,v);
   }
   
      for(int i=1;i<=n;i++) find(i);

      int cnt=0;
      for(int i=1;i<=n;i++){
         int f=fa[i];
         if(f==i) cnt++;
     }
   int ans=cha+cnt-1;
//    debug(shan);
//    debug(cnt);
   cout<<ans;
   
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}