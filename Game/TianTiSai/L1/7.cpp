#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    vector<string> s = {
    "ling", "yi", "er", "san", "si", 
    "wu", "liu", "qi", "ba", "jiu"
    };
    string in;
    cin >> in;
    rep(i, 0, (int)in.size() - 1){
        if(i) cout << " ";
        if(in[i] == '-') cout << "fu";
        else cout << s[in[i] - '0'];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}