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
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int sum = 0;
    rep(i, 1, n) sum ^= a[i];
    if(sum){
        cout << "YES" << endl;
        return;
    }

    if(*max_element(a.begin(), a.end()) < k){
        cout << "NO" << endl;
        return;
    }

    cout << (k ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}