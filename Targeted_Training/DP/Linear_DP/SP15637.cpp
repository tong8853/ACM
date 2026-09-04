#include <bits/stdc++.h>
// #include <boost/multiprecision/__int128.hpp>
using namespace std;
// using namespace boost::multiprecision;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int k;
    while(cin >> k && k != 0){
        vi row(k + 1);

        int n = 0;
        rep(i, 1, k){
            cin >> row[i];
            n += row[i];
        }

        vi prime = {2,3,5,7,11,13,17,19,23,29};
        map<int,int> cnt;

        //分解n!
        rep(i, 2, n){
            int x = i;
            for(auto p : prime){
                while(x % p == 0){
                    cnt[p]++;
                    x /= p;
                }
            }
        }

        //分解hook
        rep(i, 1, k){
            rep(j, 1, row[i]){
                int r = row[i] - j;
                int d = 0;
                rep(t, i + 1, k){
                    if(row[t] >= j) d++;
                    else break;
                }
                int hook = r + d + 1;
                int x = hook;
                for(auto p : prime){
                    while(x % p == 0){
                        cnt[p]--;
                        x /= p;
                    }
                }

            }
        }

        ll ans = 1;
        for(auto [x, y] : cnt){
            rep(i, 1, y){
                ans *= x;
            }
        }
        cout << ans << endl;
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