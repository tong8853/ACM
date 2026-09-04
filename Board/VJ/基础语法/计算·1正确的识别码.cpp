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
    int k = 0, sum = 0;
    rep(i, 0, s.size() - 3){
        if(s[i] >= '0' && s[i] <= '9'){
            k++;
            sum += (s[i] - '0') * k;
        }
    }
    if(sum % 11 == (s[s.size() - 1] - '0') || (sum % 11 == 10 && s[s.size() - 1] == 'X')) cout << "Right";
    else{
        s[s.size() - 1]=(sum % 11 == 10 ? 'X' : sum % 11 + '0');
        cout << s;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}