#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int ok[256];
void solve(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    rep(i, 0, b.size() - 1){
        ok[(int)b[i]] = 1;
    }
    rep(i, 0, a.size() - 1){
        if(!ok[(int)a[i]]){
            cout << a[i];
        }
    }
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--)solve();
}