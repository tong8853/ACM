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

inline void solve(){
    int n;cin >> n;
    vi a(n + 1);
    rep(i, 1, n)cin >> a[i];
    int k = log2(n);
    vector<vi> ma(n + 1, vi(k + 1));
    vector<vi> mi(n + 1, vi(k + 1));

    rep(i, 1, n) ma[i][0] = a[i], mi[i][0] = a[i];
    rep(i, 1, k){
        rep(j, 1, n - (1 << i) + 1){
            ma[j][i] = max(ma[j][i - 1], ma[j + (1 << (i - 1))][i - 1]);
            mi[j][i] = min(mi[j][i - 1], mi[j + (1 << (i - 1))][i - 1]);
        }
    }

    int ans = 0;
    rep(l, 1, n){
        rep(r, l, n){
            int k = log2(r - l + 1);
            int maxx = max(ma[l][k], ma[r - (1 << k) + 1][k]);
            int minx = min(mi[l][k], mi[r - (1 << k) + 1][k]);
            ans = max(ans, maxx - minx - r + l);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}