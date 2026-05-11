#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
#define debug(x) cout<<#x<<":"<<x<<endl;
#define debug2(x,y)  cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl; 
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
const int mod=998244353;
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
  string s;
  cin>>s;
  vi suf;
  int x = 1;
  deque<int> d;
  rep2(i, s.size() - 1, 0){
    if(s[i] == ')' && s[i - 1] == ')'){
        d.push_front(x);
        x = 1;
    }else if(s[i] == ')') x++;
  }
  
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}