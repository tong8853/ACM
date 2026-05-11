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
    int n, m;cin >> n >> m;
    vi fa(n + 1);
    rep(i, 1, n) fa[i] = i;
    auto find = [&](auto find, int x){
        if(x == fa[x]) return x;
        return fa[x] = find(find, fa[x]);
    };

    auto merge = [&](int x, int y){
        x = find(find, x), y = find(find, y);
        if(x != y) fa[x] = y;
    };
    rep(i, 1, m){
        int x, y;cin >> x >> y;
        merge(x, y);
    }
    int block  = 0;
    rep(i, 1, n){
        if(fa[i] == i) block++;
    }
    cout << block - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}