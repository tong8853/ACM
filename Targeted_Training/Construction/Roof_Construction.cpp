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
    int x = n - 1;
    int k  =0;
    while(x > 1){
        x >>= 1;
        k++;
    }
    rep2(i, (1 << k) - 1, 0) cout << i << ' ';
    rep(i, (1 << k), n - 1) cout << i << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}