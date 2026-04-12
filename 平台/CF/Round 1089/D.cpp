#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define pb push_back    
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

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

inline void solve(){
    int n;cin >> n;
    vll a(n + 1), b(n + 1), c(n + 1);
    read(a, 1, n), read(b, 1, n);
    int ans = 0;
    rep(i, 1, n){
        if(i == 1) c[i] = __gcd(a[i], a[i + 1]);
        else if(i == n) c[i] = __gcd(a[i - 1], a[i]);
        else c[i] = lcm(__gcd(a[i - 1], a[i]), __gcd(a[i], a[i + 1]));
    }
    rep(i, 1, n){
        if(i == 1){
            if(a[i] != c[i]){
                if(c[i] <= b[i]) ans++;
            }else{
                rep(j, 2, 10000000){
                    if(j * c[i] <= b[i]){
                        ans++;
                        break;
                    }
                }
            }
        }else if(i == n){
            if(a[i] != c[i]){
                if(c[i] <= b[i]) ans++;
            }else{
                rep(j, 2, 10000000){
                    if(j * c[i] <= b[i]){
                        ans++;
                        break;
                    }
                }
            }
        }else{
            if(a[i] != c[i]){
                if(c[i] <= b[i]) ans++;
            }else{
                rep(j, 2, 10000000){
                    if(j * c[i] <= b[i]){
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}