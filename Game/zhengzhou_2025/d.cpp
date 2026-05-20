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
   string s;
   cin>>s;
   int num=stoi(s);
   int sqt=sqrt(num);
   bool ok1=((sqt*sqt)==num);
   int sum=0;
   for(auto c:s) sum+=c-'0';
   int sqtt=sqrt(sum);
   bool ok2=((sqtt*sqtt)==sum);
   if(ok1&&ok2){
       cout<<"Yes\n";
   } else cout<<"No\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}