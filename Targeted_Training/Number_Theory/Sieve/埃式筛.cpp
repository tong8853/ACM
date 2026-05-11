#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int N = 1e6+10;

void solve(){
    bool isprime[N];
    fill(isprime, isprime+N+1, 1);
    vi prime;
    isprime[0] = isprime[1] = 0;
    rep(i, 2, N - 1){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j = (ll)i * i; j <= N - 1; j += i){
                isprime[j] = false;
            }
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