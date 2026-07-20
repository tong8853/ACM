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
    int ans = 0;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int mid = n / 2 + 1;
    rep(i, 1, mid - 1){
        if(!(a[i] == a[mid] && a[n - i + 1] == a[mid])) ans++; 
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}