#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;

int n, m;

array<int, 2> a[N];

struct BIT{
    int val[N];
    void init(){
        REP(i, 1, n) val[i] = 0;
    }
    inline int lowbit(int x){ return x&(-x); }
    void add(int p, int x=1){
        while(p <= n){
            val[p] += x;
            p += lowbit(p);
        }
    }
    int sum(int p){
        int res = 0;
        while(p){
            res += val[p];
            p -= lowbit(p);
        }
        return res;
    }
}bit;

void solve(){
    cin>>n;
    
    bit.init();
    map<int, int> mp;
    REP(i, 1, n){
        cin>>a[i][0]>>a[i][1];
        mp[a[i][0]] = i;
    }
    
    int now = 0;
    for(auto [x, i] : mp){
        a[i][0] = ++now;            // 离散化
    }
    sort(a+1, a+n+1, [](auto x, auto y)
        { return x[1] < y[1]; }     // 这里按右端点排序, 其实按左端点排序也是ok的
    );

    // 统计逆序对
    ll ans = 0;
    REP(i, 1, n){
        int cnt = bit.sum(n) - bit.sum(a[i][0]);
        ans += cnt;
        bit.add(a[i][0]);
    }
    cout<<ans<<endl;
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