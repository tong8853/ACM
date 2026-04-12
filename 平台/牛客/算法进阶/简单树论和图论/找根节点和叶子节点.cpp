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
ll p = 998244353; 

int n;

inline void solve(){
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    vi indu(n + 1);
    vi outdu(n + 1);
    rep(i, 1, n - 1){
        int u, v;cin >> u >> v;
        outdu[u]++;
        indu[v]++;
    }
    int root = 0;
    vi ye;
    rep(i, 1, n){
        if(indu[i] == 0){
            root = i;
            break;
        }
    }
    rep(i, 1, n){
        if(outdu[i] == 0) ye.push_back(i);
    }
    cout << root << endl;
    rep(i, 0, ye.size() - 1){
        cout << ye[i] << (i == ye.size() - 1 ? "" : " ");
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}