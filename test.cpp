#include <iostream>
#include <algorithm>
#include <numeric>
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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(a, lcm(b, c));
    ll ans = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}
