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
    vll a(n + 1);
    vll ans;
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    rep(i, 1, n / 2){
        int j = (n % 2 ? n - i : n - i + 1);
        ans.push_back(a[i] * a[j]);
    }
    if(n % 2) ans.push_back(a[n]);
    cout << *max_element(ans.begin(), ans.end())  - *min_element(ans.begin(), ans.end()) << endl; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}