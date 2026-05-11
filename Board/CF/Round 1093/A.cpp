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
    vi a(n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ok = 1;
    rep(i, 1, n - 1){
        if(a[i - 1]==a[i]){
            ok = 0;
            break;
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    vi ans;
    rep2(i, n - 1, 0) cout << a[i] << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}