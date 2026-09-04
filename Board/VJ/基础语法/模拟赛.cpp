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
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> cnt(k + 1);
    rep(i, 1, n){
        rep(j, 1, m){
            int x;
            cin >> x;
            cnt[x].insert(j);
        }
    }
    rep(i, 1, k){
        cout << cnt[i].size() << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}