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

const int N = 1e6+1000;
const ll p = 998244353;
vi pr;
int zhi[N];

inline void solve(){
    vi he(N);
    he[1] = 1;
    rep(i, 2, N){
        if(!he[i]) pr.push_back(i);
        for(auto p : pr){
            if(i * p > N) break;
            he[i * p] = 1;
            if(i % p == 0) break;
        }
    }
    for(auto i : pr) zhi[i] = 1;

    int m,n;cin >> m >> n;
    if(m > 2 || n < 2){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    rep(i, 3, n - 1){
        rep(j, i + 1, n){
            int a = 2 * i + j;
            int b = 2 * j + i;
            int c = i * j + 2;
            if(zhi[a] && zhi[b] && zhi[c] && zhi[i] && zhi[j]){
                ans++;
                //cout << 2 << " " << i << " " << j << endl;
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}