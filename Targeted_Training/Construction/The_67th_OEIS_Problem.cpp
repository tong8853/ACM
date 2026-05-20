#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e6+5;
void solve(){
    int t;
    cin >> t;
    vll p;
    vector<bool> isp(N, true);
    isp[1] = isp[0] = 0;
    auto init = [&](void) -> void{
        for(ll i = 2; i < N; ++i){
            if(isp[i]){
                p.push_back(i);
                for(ll j = 2 * i; j < N; j += i){
                    isp[j] = 0;
                }
            }
        }
    };
    init();
    while(t--){
        int n;
        cin >> n;
        rep(i, 1, n){
            cout << p[i] * p[i - 1] << " ";
        }
        cout << endl;
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