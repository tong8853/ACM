#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
using ll = long long;
using vi = vector<int>;

void solve(){
    string s;
    cin >> s;
    int c2 = 0, c3 = 0, sum = 0;
    for(auto c : s){
        if(c == '2') c2++;
        else if(c == '3') c3++;
        sum += c - '0';
    }
    rep(i, 0, min(c2, 8)){
        rep(j, 0, min(c3, 2)){
            if((sum + i * 2 + j * 6) % 9 == 0){
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
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}