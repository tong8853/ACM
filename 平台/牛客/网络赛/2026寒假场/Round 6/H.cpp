#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2048, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

bool v[N];
inline void solve(){
    int n;cin >> n;
    vi a(n + 1), b(n + 1);
    read(a, 1, n), read(b, 1, n);
    v[0] = 1;
    rep(i, 1, n){
        bool nv[N];
        memset(nv, 0, N);
        rep(k, 0, N - 1){
            if(v[k]){
                nv[max(0, k - a[i])] = 1;
                nv[k ^ b[i]] = 1;
            }
        }
        rep(i, 0, N - 1){
            v[i] = nv[i];
        }
    }
    per(i, N - 1, 0){
        if(v[i]){
            cout << i;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}