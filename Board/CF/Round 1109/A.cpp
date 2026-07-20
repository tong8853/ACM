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
    int  l;
    cin >> l;
    string s;
    cin >> s;
    int  i = 0;
    int maxx = 0, x = 0;
    while(i < l){
        if(s[i] == '#') x++;
        else x = 0;
        maxx = max(maxx, x);
        i++;
    }
    cout << (maxx + 1) / 2 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}