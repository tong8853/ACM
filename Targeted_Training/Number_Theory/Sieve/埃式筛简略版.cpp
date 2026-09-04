#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e7 + 10;
void solve(){
    vector<bool> isprime(N + 1, 1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i * i <= N; i++){
        if(isprime[i]){   //埃式筛核心：每当发现一个素数 p，就把它的所有倍数标记为合数。
            for(int j = i * i; j <= N; j += i){
                isprime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}