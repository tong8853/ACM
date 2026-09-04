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
    string s;
    cin >> n;
    cin >> s;
    s = " " + s;
    vi a(n + 1);
    int prex = 0;
    rep(i, 1, n){
        if(s[i] == 'x') prex++;
        a[i] = prex;
    }
    rep(k, 1, n){
        int ans = lower_bound(a.begin(), a.end(), k) - a.begin();
        cout << (ans > n ? n : ans) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}