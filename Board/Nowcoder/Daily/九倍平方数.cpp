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
    int n = s.size();
    s = " " + s;
    int cnt2 = 0, cnt3 = 0;
    int sum = 0;
    rep(i, 1, n){
        if(s[i] == '2') cnt2++;
        if(s[i] == '3') cnt3++;
        sum = (sum + s[i] - '0') % 9;
    }
    rep(i, 0, min(cnt2, 8)){
        rep(j, 0, min(cnt3, 3)){
            if((sum + 2 * i + 6 * j) % 9 == 0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}