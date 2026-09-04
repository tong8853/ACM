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
    vi a(n + 1);
    ll mx = 0;
    rep(i, 1, n) cin >> a[i], mx += a[i];

    // //埃式筛
    // vi isprime(mx + 1, 1);

    // isprime[0] = isprime[1] = 0;
    // for(int i = 2; i * i <= mx; i++){
    //     if(isprime[i]){
    //         for(int j = i * i; j <= mx; j += i){
    //             isprime[j] = 0;
    //         }
    //     }
    // }

    auto isprime = [&](int x) -> bool{
        if(x == 1 || x != 2 && x % 2 == 0) return 0;
        for(int i = 3; i * i <= x; i++) if(x % i == 0) return 0;
        return 1;
    };


    ll ans = 0;
    auto dfs = [&](auto self, int i, ll num, int cnt){

        if(cnt == k){
            if(isprime(num)){
                ans++;
            }
            return;
        }

        rep(j, i + 1, n){
            if(n - j + 1 >= k - cnt) self(self, j, num + a[j], cnt + 1);
        }
    };

    dfs(dfs, 0, 0, 0);
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