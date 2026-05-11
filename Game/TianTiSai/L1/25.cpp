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
    getline(cin, s);
    int ok = 1;
    rep(i, 0, s.size() - 1){
        if(if(s[i] != '0' || s[i] != '1' || s[i] != '2' ||s[i] != '3' ||s[i] != '4' ||s[i] != '5' ||s[i] != '6' ||s[i] != '7' ||s[i] != '8' || s[i] != '9' || s[i] != ' '){
            ok = 0;
            break;
        }
    }
    if(!ok) cout << "? + ? = ?";
    else{
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}