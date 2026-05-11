#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    ll n, m, l;cin >> n >> m >> l;
    vll a(n + 1);
    vll b(m + 1);
    read(a, 1, n);
    read(b, 1, m);
    rep(i, 1, n) a[i] += a[i - 1];
    rep(i, 1, m) b[i] += b[i - 1];
    ll L = 0, R = l;
    ll k = 1;//第k个缝隙
    bool ok = false;
    if(a[k] > L && a[k] < R) ok = true;
    rep(i, 1, m){//第i个步子
        L = b[i];
        R = b[i] + l;
        while(k <= n && a[k] <= L) k++;
        if(k <= n && a[k] > L && a[k] < R){
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}