#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll f[11];
void solve(){
    f[1] = 1;
    rep(i, 2, 10) f[i] = f[i - 1] * i;
    rep(i, 2, 10) f[i] += f[i - 1];
    int n;
    cin >> n;
    cout << f[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}