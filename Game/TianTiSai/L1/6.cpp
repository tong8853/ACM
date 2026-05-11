#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    ll n;cin >> n;
    PII ans;
    ll len = 0;
    rep(l, 2, 50){
        rep(r, l, 50){
            ll x = 1;
            rep(i, l, r){
                x *= i;
            }
            if(n % x == 0){
                if(r - l + 1 > len){
                    len = r - l + 1;
                    ans = {l, r};
                }
            }
        }
    }
    if(len == 0){
        cout << 1 << endl << n << endl;
        return;
    }
    cout << len << endl;
    rep(i, ans.ff, ans.ss){
        if(i != ans.ff) cout << "*";
        cout << i;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}