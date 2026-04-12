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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    ll n, m, q;cin >> n >> m >> q;
    ll cnt_x = 0, cnt_y = 0;
    set<int> st_x;
    set<int> st_y;
    while(q--){
        ll a, b;cin >> a >> b;
        if(a == 0) st_x.insert(b);
        else st_y.insert(b);
    }
    cnt_x = st_x.size();
    cnt_y = st_y.size();
    cout << n * m - cnt_x * m - cnt_y * n + cnt_x * cnt_y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}