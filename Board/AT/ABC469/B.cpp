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
    if(n == 1){
        cout << (s[n - 1] == 'x' ? 1 : 0) << endl;
        return;
    }

    int ans = 0;
    rep(i, 0, n - 1){
        if(s[i] == 'x'){
            if(i == 0 && s[i + 1] == 'x') ans++;
            else if(i == n - 1 && s[i - 1] == 'x') ans++;
            else if(s[i - 1] == 'x' && s[i + 1] == 'x') ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}