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
    vi fa(n + 1);
    rep(i, 1, n) fa[i] = i;
    auto find = [&](auto self, int x){
        if(x == fa[x]) return x;
        return fa[x] = self(self, fa[x]);
    };

    auto merge = [&](int x, int y){
        x = find(find, x), y = find(find, y);
        if(x != y) fa[x] = y;
    };
    int ans = 0, comp = 0;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    rep(i, 1, n){
        if(i == fa[i]) comp++;
    }
    ans += m - n + 2 * comp - 1;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}