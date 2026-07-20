#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;



void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n + 1), fa(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) fa[i] = i;

    auto find = [&](auto self, int x)->int{
        if(x == fa[x]) return x;
        return fa[x] = self(self, fa[x]);
    };

    auto merge = [&](int u, int v){
        u = find(find, u), v = find(find, v);
        fa[u] = v;
    };
    while(m--){
        int u, v;
        cin >> u >> v;
        if(!a[u] && !a[v]){
            merge(u, v);
        }
    }
    cout << (find(find, 1) == find(find, n) ? "Yes" : "No") << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}