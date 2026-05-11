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
    auto isprime = [&](ll x){
        if(x < 2) return false; 
        if(x == 2) return true;
        for(ll i = 2; i * i <= x; ++i){
            if(x % i == 0) return false;
        }
        return true;
    };
    ll x;cin >> x;
    cout << (isprime(x) ? "Yes" : "No") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}