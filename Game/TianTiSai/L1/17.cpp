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
    int ok1 = 0;
    int ok2 = 0;
    double cnt = 0; 
    if(s[0] == '-') ok1 = 1;
    if((s[s.size() - 1] - '0') % 2 == 0) ok2 = 1;
    rep(i, 0, s.size() - 1){
        if(s[i] == '-') continue;
        if(s[i] == '2') cnt++;
    }
    double wei = s.size() - ok1;
    cout << fixed << setprecision(2) << (cnt / wei) * (ok1 == 1 ? 1.5 : 1) * (ok2 == 1 ? 2 : 1) * 100 << '%';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}