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
    int n;cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    int len = s.size();
    int col = (len + n  -1) / n;
    vector<string> res(n + 1, string(col + 1, ' '));
    int k = 0;
    for(int i = col; i > 0; i--){
        rep(j, 1, n){
            res[j][i] = s[k++];
            if(k > s.size() - 1) break;
        }
    }
    rep(i, 1, n){
        rep(j, 1, col){
            cout << res[i][j];
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}