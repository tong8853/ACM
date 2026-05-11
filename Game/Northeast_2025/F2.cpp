#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

//在K进制下，一个最简分数a/b有限小数，当且仅当分母b的所有质因子都是基数K的质因子的子集

void solve(){
    ll p, x, k;
    cin >> p >> x >> k;
    map<ll, int> cnt;
    auto get = [&](ll n, ll c){
        for(ll x = 2; x * x <= n; x++){
            while(n % x == 0){
                cnt[x] += c;
                n /= x;
            }
        }
        if(n > 1) cnt[n] += c;
    };

    get(p, 1);
    get(k, 100);

    ll ans = 0;
    vector a(cnt.rbegin(), cnt.rend());
    auto dfs = [&](auto self, int i, ll n){
        if(i == a.size()){
            ans++;
            return;
        }
        
        rep(j, 0, a[i].second){
            self(self, i+1, n);
            if(n > x / a[i].first) break;
            n *= a[i].first;
        }
    };
    dfs(dfs, 0, 1);
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