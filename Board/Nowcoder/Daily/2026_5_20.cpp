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
    auto find = [&](int x){
        if(x  == 1) return 2;
        else if(x == 2) return 3;
        else if(x == 3) return 5;
        else if(x == 4) return 5;
        else if(x == 5) return 7;
        else return 11;
    };

    string s;
    cin >> s;
    int x = s[0] - '0';
    cout << find(x);
    rep(i, 1, s.size() - 1) cout << 0;
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}