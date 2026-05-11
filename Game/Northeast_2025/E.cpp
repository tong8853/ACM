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
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    int ca = 0;
    for(auto c : a) if(c == '1') ca++;
    int ans = -1;
    int mod = (1 << k);
    rep(j, 0, k){ //先算出b，再验证是否合法
        int b = (ca + j) % mod;
        if(__builtin_popcount(b) == j){
            if(ans == -1 || b < ans) ans = b;
        }
    }

    if(ans == -1) cout << "None" << endl;
    else{
        rep2(i, k - 1, 0){
            cout << ((ans >> i) & 1);
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}