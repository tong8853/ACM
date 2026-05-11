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
    int x, n;
    cin >> x >> n;
    rep(i, x, 10000){
        string s = to_string(i);
        while(s.size() < 4) s = "0" + s;

        set<char> st;
        rep(j, 0, s.size() - 1) st.insert(s[j]);
        if(st.size() == n){
            cout << i - x << " " << setfill('0') << setw(4) << i;
            return;
        }
     }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}