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
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    map<int,int>use,cnt;

    for(int i=1;i<=n;i++) {
        cin>>a[i];
        use[i]=a[i];
        cnt[a[i]]++;
    }
    
    while(m--){
        int l,r,d;
        cin>>l>>r>>d;
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}