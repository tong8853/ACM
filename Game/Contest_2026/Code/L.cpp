#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, M = 1e6+5;

int n, m;

int a[N];

void solve(){
    cin >> n;
    REP(i, 1, n) cin >> a[i];

    ll ans = 0;
    REP(i, 1, n) {
        ll sz = n / 2 + (n % 2 == 1 && i % 2 == 1);
        ans = max(ans, a[i] + sz);
    }

    cout << ans << endl;
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    cin>>_;
    assert(1<=_ && _<=1e3);
    while(_--){
        solve();
    }
    return 0;
}