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

const int N = 1e5 + 10;
int n, root, maxd = 0;
vi adj[N];
vi ans;

inline void solve(){
    cin >> n;
    rep(i, 1, n){
        int par;cin >> par;
        if(par == -1) root = i;
        else adj[par].push_back(i);
    }

    queue<PII> q;
    q.push({root, 1});
    while(!q.empty()){
        auto [u, d] = q.front();q.pop();
        if(d > maxd){
            ans = {u}; //重置ans，并添加该点
            maxd = d;
        }else if(d == maxd) ans.push_back(u);
        for(auto v : adj[u]) q.push({v, d + 1});
    }
    cout << maxd << endl;
    sort(all(ans));
    rep(i, 0, ans.size() - 1) cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}