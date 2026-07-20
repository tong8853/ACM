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
    vector<string> ans;
    string s1 = "";
    rep(i, 0, s.size() - 1){
        int c = s[i] - '0';
        if(c % 2 == 0){
            s1 += s[i];
            ans.push_back(s1);
            s1 = "";
        }else{
            s1 += s[i];
        }
    }
    sort(ans.begin(), ans.end(), [&](const string &x, const string &y){
        if(x.size() != y.size()) return x.size() < y.size();
        return x < y;
    });
    for(auto &x : ans) cout << x << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}