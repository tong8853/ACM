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
    char c;
    cin >> n >> c;
    rep(i, 1, (n + 1) / 2){
        rep(j, 1, n){
            cout << c;
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}