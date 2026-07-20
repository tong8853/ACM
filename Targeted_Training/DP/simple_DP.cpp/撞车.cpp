#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define ff first
#define ss second

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    rep(i, 1, n){
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin() + 1, a.end());
    vi v(n + 1);
    rep(i, 1, n) v[i] = a[i].ss;
    vi ans;
    rep(i, 1, n){
        auto pos = upper_bound(ans.begin(), ans.end(), v[i]);
        if(pos == ans.end()) ans.push_back(v[i]);
        else *pos = v[i];
    }
    cout << n - ans.size() << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}