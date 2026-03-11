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

struct T{
    int id;
    ll x, y;
    double wi;//y减去1的收益
    bool operator<(const T& x) const{
        return wi < x.wi;
    }
};

inline double cal_wi(ll x, ll y){
    if(y == 0) return 0;
    return sqrt((double)x * x + (double)y * y) - sqrt((double)x * x + (double)(y - 1) * (y - 1));
}

inline void solve(){
    ll n, w;cin >> n >> w;
    priority_queue<T> pq;
    rep(i, 0, n - 1){
        ll x, y;cin >> x >> y;
        pq.push({i, x, y, cal_wi(x, y)});
    }
    while(w > 0 && !pq.empty()){
        T t = pq.top();
        if(t.wi == 0) break;
        pq.pop();
        t.y--;
        w--;
        t.wi = cal_wi(t.x, t.y);
        pq.push(t);
    }
    double ans = 0;
    rep(i, 1, n){
        T t = pq.top();
        ans += sqrt((double)t.x * t.x + (double)t.y * t.y);
        pq.pop();
    }
    cout << fixed << setprecision(10) << ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}