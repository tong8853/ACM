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
    ll n, m;cin >> n >> m;
    vll a(n);
    read(a, 0, n - 1);
    ll ans = 4e5 + 5;
    ll l = 0, r = 4e5;
    ll get = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        get = 0;
        rep(i, 0, n- 1){
            get += (a[i] > mid ? a[i] - mid : 0);
        }
        if(get < m){
            r = mid - 1;
        }else{
            l = mid + 1;
            ans = mid;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}