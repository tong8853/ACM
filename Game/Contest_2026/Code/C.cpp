#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;

int n, m;

int a[N];

pii calc(int d, int k){
    int g = __gcd(d, k);
    d /= g, k /= g;
    return {d, k};
}

void solve(){
    cin>>n;
    string s; cin>>s;
    int d=0, k=0;
    map<pii, int> f;
    for(auto c : s){
        if(c == '0') ++d;
        else ++k;
        ++f[calc(d, k)];
    }
    cout<<f[calc(d, k)]<<endl;
    return ;
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}