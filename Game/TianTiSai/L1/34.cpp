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
    int n;cin >> n;
    vi a(1001);
    rep(i, 1, n){
        int x;cin >> x;
        rep(j, 1, x){
            int m;cin >> m;
            a[m]++;
        }
    }
    cout << max_element(a.begin(), a.end(), [](int l, int r){
        return l <= r;
    }) - a.begin() << " " << *max_element(a.begin(), a.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}