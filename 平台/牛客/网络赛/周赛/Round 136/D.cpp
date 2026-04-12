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
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());

    int mid = (n + 1) / 2;
    int M = a[mid];

    if(a[1] == a[n]){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    rep(i, 1, n){
        if(a[i] == M){
            ans = max(ans, 2 * (i - 1));
            break;
        }
    }

    per(i, n, 1){
        if(a[i] == M){
            ans = max(ans, 2 * (n - i) - 1);
            break;
        }
    }
    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}