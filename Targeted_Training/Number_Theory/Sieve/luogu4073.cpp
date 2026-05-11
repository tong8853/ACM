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
    vector<bool> isprime(n + 1, 1);
    vi prime;
    isprime[0] = isprime[1] = 0;
    rep(i, 2, n){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j = (ll)i * i; j <= n; j += i){
                isprime[j] = 0;
            }
        }
    }
    cout << prime.size() + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}