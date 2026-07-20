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
    string s;
    cin >> s;
    s = " " + s;
    rep(i, 1, 2){
        cout << s[i];
        if((s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z' || s[i + 1] >= 'A' && s[i + 1] <= 'Z')) cout << '.';
    }
    cout << s[3];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}