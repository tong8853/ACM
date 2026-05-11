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
    int a[3];
    rep(i, 0, 2) cin >> a[i];
    sort(a, a + 3);
    rep(i, 0, 2){
        if(i) cout << "->";
        cout << a[i];
    }
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--)solve();
}