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
const ll p = 998244353;

bool cmp(ll a, ll b){
    return a > b;
}

inline void solve(){
    int n;cin >> n;
    ll maxa = 0, maxb = 0;
    vll a, b;
    vll ans(n);
    rep(i, 1, n){
        ll x;cin >> x;
        if(x % 2) a.push_back(x);
        else b.push_back(x);
    }
    int i = a.size();
    int j = b.size();
    sort(all(a), cmp);
    sort(all(b), cmp);
    rep(i, 1, n - i) a.push_back(0);
    rep(i, 1, n - j) b.push_back(0);
    vll qzha(n);
    vll qzhb(n);
    qzha[0] = a[0];
    qzhb[0] = b[0];
    rep(w, 1, j) qzha[w] = qzha[w - 1] + b[w - 1];
    rep(w, 1, i) qzhb[w] = qzhb[w - 1] + a[w - 1];
    rep(w, 0, n - 1) ans[w] = max(qzha[w], qzhb[w]);
    for(auto &x : ans){
        cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}