#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5;
const int M = 1e6+5;
const ll INF = 1e15;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n, x;cin >> n >> x;
    vll a(n + 1), b(n + 1), mx(n + 1);
    read(a, 1, n);
    read(b, 1, n);
    ll s = 0;
    rep(i, 1, n){
        ll need = a[i] - s;//第i张牌需要的能量
        mx[i] = max(mx[i - 1], need);//mx[i]前i张牌种需要的最大能量
        s += b[i] - a[i];//累计能量变化
    }
    if(s >= 0){ //说明每轮能量是单调不减的
        if(x >= mx[n]){ //初始能量大于能走到n需要的能量
            cout << "Infinity" << endl;
            return;
        }
        cout << (upper_bound(mx.begin()+1, mx.begin()+n+1, x) - mx.begin() - 1) << endl;
        return; 
    }

    //第k轮能走完需要满足 x - (k - 1)d >= mx[n]
    ll d = -s, lun = 0;
    if(x >= mx[n]) lun = (x - mx[n]) / d + 1;    
    ll cur = x - lun * d;
    ll p = upper_bound(mx.begin()+1, mx.begin()+n+1, cur) - mx.begin() - 1;
    cout << lun * n  + p << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}