#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout<<#x<<":"<<x<<endl;
#define debug2(x,y)  cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl; 
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int n, k;
    cin >> n >> k;
    ll mod = (1 << k);
    string a;cin >> a;
    ll ca = 0;
    rep(i, 0, a.size() - 1){
        if(a[i] == '1') ca++;
    }
    rep(i, 1, mod - 1){
        rep(j, 1, k){
            if((ca + j) % mod == i){
                ll cnt = 0;
                ll x = i;
                while(x > 0){
                    if(x & 1) cnt++;    
                    x >>= 1;
                }
                if(cnt == j){
                    string s;
                    while(i > 0){
                        if(i & 1){
                            s.push_back('1');
                        }else s.push_back('0');
                        i >>= 1;
                    }
                    rep(q, s.size() + 1, k) cout << '0';
                    rep2(q, s.size() - 1, 0) cout << s[q];
                    cout << endl;
                    return;
                }
            }
         }
    }
    cout << "None" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}