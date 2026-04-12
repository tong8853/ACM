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

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        b >>= 1;
        a *= a;
    }
    return res;
}

vi a(32);
inline void solve(){
    ll x;cin >> x;
    a[1] = 2;
    rep(i, 2, 31) a[i] = 2 * a[i - 1];
    int maxk = upper_bound(all(a), x) - a.begin() - 1;
    per(i, maxk, 1){
        ll sum = 0;
        int j = 1;
        while(sum < x){
            sum += qpow(j, i);
            j++;
        }
        if(sum == x){
            rep(k, 1, j - 1){
                if(k != j - 1)cout << k << "^" << i << "+";
                else cout << k << "^" << i << endl; 
            }
            return;
        }
    }
    cout << "Impossible for " << x << "." << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}