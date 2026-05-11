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
    deque<int> ans;
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) if(a[i] % 3 != 0 && a[i] % 2 != 0) ans.push_back(a[i]);
    rep(i, 0, n - 1) if(a[i] % 3 == 0 && a[i] % 2 != 0) ans.push_back(a[i]);
    rep(i, 0, n - 1) if(a[i] % 3 != 0 && a[i] % 2 == 0) ans.push_front(a[i]);
    rep(i, 0, n - 1) if(a[i] % 3 == 0 && a[i] % 2 == 0) ans.push_front(a[i]);
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}