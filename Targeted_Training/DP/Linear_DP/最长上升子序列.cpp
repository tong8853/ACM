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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi LIS;
    for(auto &x : a){
        auto pos = lower_bound(LIS.begin(), LIS.end(), x) - LIS.begin();
        if(pos == LIS.size()) LIS.push_back(x);
        else LIS[pos] = x;
    }
    cout << LIS.size() << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}