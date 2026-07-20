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
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    vi a, b;
    rep(i, 1, n){
        if(s[i] != t[i]){
            if(s[i] == '0') a.push_back(i);
            else b.push_back(i);
        }
    }
    if(a.size()) cout << 2 * a.size() + 1 << endl;
    else cout << 0 << endl;
    
    if(a.size()){
        rep(i, 0, a.size() - 1){
            cout << a[i] << endl << b[i] << endl;
        }
    }
    if(a.size()) cout << a[0] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}