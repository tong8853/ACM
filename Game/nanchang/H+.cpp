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
    ll n;
    cin >> n;
    vll a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vll cha(n + 1);
    rep(i, 1, n){
        cha[i] = a[i] - i;
        if(cha[i] < 0){
            cout << -1 << endl;
            return;
        }
    }
    vll last(n + 1);
    last[n] = cha[n];
    rep2(i, n - 1, 1){
        last[i] = min(last[i + 1], cha[i]);
    }
    ll ans = 0;
    vll c(n + 1);
    ll shao = 0;
    rep(i, 1, n){
        if(i != 1){
            if(last[i] != last[i - 1]){
                if(shao){
                    
                }
            }
        }
        shao += cha[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}