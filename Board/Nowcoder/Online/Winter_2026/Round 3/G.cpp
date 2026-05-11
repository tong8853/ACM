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
    int n, m;cin >> n >> m;
    vi a(n), b(m);
    ll sum1 = 0;
    ll sum2 = 0;
    rep(i, 0, n - 1) cin >> a[i], sum1 += a[i];
    rep(i, 0, m - 1) cin >> b[i], sum2 += b[i];
    sort(all(a)), sort(all(b));
    if(sum1 == sum2) cout << 1 << endl;
    else if(sum1 > sum2){
        ll diff = sum1 - sum2;
        int i = n - 1;
        while(diff > 0){
            diff -= a[i];
            i--;
        }
        ll ans = n - 1 - i;
        cout << ans << endl;
    }else{
        ll diff = sum2 - sum1;
        int i = m - 1;
        while(diff > 0){
            diff -= b[i];
            i--;
        }
        ll ans = m - 1 - i;
        cout << ans << endl;
    }    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}