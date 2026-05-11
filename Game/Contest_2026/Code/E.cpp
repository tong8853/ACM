#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define QAQ(x) cout << #x << ": " << (x) << endl, exit(0);
#define endl '\n'
#define int long long
using namespace std; 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5, M = 1e6 + 5;
const ll INF = 1e15, mod = 998244353; 

int n, m;

int a[N];

void solve() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    if (x == 0)
        cout<<"YES"<<endl;
    else {
        int cnt = 0, cur = 0;
        for (int i = 1; i <= n; i++) {
            cur ^= a[i];
            if (cur == x)
                cnt++, cur = 0;
        }
        if (cnt >= 2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}