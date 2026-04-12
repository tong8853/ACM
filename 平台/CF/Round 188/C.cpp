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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll ab = lcm(a, b);
    ll ac = lcm(a, c);
    ll bc = lcm(b, c);
    ll abc = lcm(a, bc);
    ll na = m / a, nb = m / b, nc = m / c;
    ll nab = m / ab, nac = m / ac, nbc = m / bc;
    ll nabc = m / abc;
    ll ansA = 6 * na - 3 * nab - 3 * nac + 2 * nabc;
    ll ansB = 6 * nb - 3 * nab - 3 * nbc + 2 * nabc;
    ll ansC = 6 * nc - 3 * nac - 3 * nbc + 2 * nabc;
    cout << ansA  << " " << ansB << " " << ansC << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}