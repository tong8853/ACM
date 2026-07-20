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
    int n, x, y;
    cin >> n >> x >> y;
    vi fa(n + 1), a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        fa[i] = i;
    }

    auto find = [&](auto self, int x) -> int{
        if(x == fa[x]) return x;
        return fa[x] = self(self, fa[x]);
    };

    auto merge = [&](int x, int y){
        x = find(find, x), y = find(find, y);
        fa[x] = y;
    };

    //连接所有相差x的位置
    for(int i = 1; i + x <= n; i++){
        merge(i, i + x);
    }
    //连接所有相差y的位置
    for(int i = 1; i + y <= n; i++){
        merge(i, i + y);
    }
    rep(i, 1, n){
        if(find(find, a[i]) != find(find, i)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}