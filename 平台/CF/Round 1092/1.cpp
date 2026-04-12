#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 2e5+5;
const ll p = 998244353;

inline void solve(){
    int n, k;cin >> n >> k;
    vi a(k + 1);
    vector<PII> b(n + 1); //{lever, id}
    rep(i, 1, k) cin >> a[i];
    rep(i, 1, n){
        cin >> b[i].ff;
        b[i].ss = i;
    }
    sort(b.begin() + 1, b.end());
    ll ans = 0;
    ll sum = 0;
    rep(i, 1, n) sum += b[i].ff;
    ans = n * (k + 1) - sum;
    if(ans > 1000){
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
    int x = n;
    rep(i, 0, ans - 1){
        if(b[x].ff < k + 1){
            b[x].ff++;
            if(i) cout << " ";
            cout << b[x].ss;
        }else{
            x--;
            if(b[x].ff >= k + 1){
                i--;
                continue;
            }
            b[x].ff++;
            if(i) cout << " ";
            cout << b[x].ss;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}