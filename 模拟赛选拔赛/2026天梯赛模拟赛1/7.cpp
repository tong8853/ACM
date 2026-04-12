#include <bits/stdc++.h>
#include <vector>
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

int n, m;
vi fa;

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x != y) fa[x] = y;
}

inline void solve(){
    cin >> n >> m;
    fa.resize(m + 1);
    rep(i, 1, m) fa[i] = i;
    rep(i, 1, n){
        int k;cin >> k;
        vi a(k + 1);
        rep(j, 1, k) cin >> a[j];
        rep(j, 2, k) merge(a[j - 1], a[j]); 
    }
    vi mn(m + 1, (int)1e9);
    rep(i, 1, m){
        int f = find(i);
        mn[f] = min(mn[f], i);
    }
    vector<int> ans;
    rep(i, 1, m){
        if(fa[i] == i && mn[i] != (int)1e9) ans.push_back(mn[i]);
    }
    sort(all(ans));
    rep(i, 0, (int)ans.size() - 1){
        if(i) cout << " ";
        cout << ans[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;//cin >> T;
    while(T--)solve();
}