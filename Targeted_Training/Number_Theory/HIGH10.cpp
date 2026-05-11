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
    int N;
    cin >> N;
    vector<bool> isprime(N + 1);
    vi prime;
    rep(i, 2, N) isprime[i] = 1;
    rep(i, 2, N){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j = (ll)i * i; j <= N; j += i){
                isprime[j] = 0;
            }
        }
    }
    int n = prime.size();
    ll ans = 0;
    rep(i, 0, n - 1){
        ll c = prime[i] * prime[i];
        if(c > 2 * prime[n - 1]) break;
        rep(j, 0, n - 1){
            if(c >= prime[j] && (c - prime[j]) <= prime[n - 1]  &&isprime[c - prime[j]]){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}