#include <bits/stdc++.h>
#include <vector>
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

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

inline void solve(){
    int n;cin >> n;
    vi a(n + 1), b(n + 1);
    int l = a.size();
    read(a, 1, n), read(b, 1, n);
    int ans = 0;
    rep(i, 1, n){
        if(i == 1){
            int maxx = __gcd(a[i], a[i + 1]);
            if(maxx <= b[i] && a[i] != maxx) ans++;
        }else if(i == n){
            int maxx = __gcd(a[i - 1], a[i]);
            if(maxx <= b[i] && a[i] != maxx) ans++;
        }else{
            int maxx = lcm(__gcd(a[i - 1], a[i]), __gcd(a[i], a[i + 1]));
            if(maxx <= b[i] && a[i] != maxx) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}