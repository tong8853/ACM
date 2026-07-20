#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define xx first
#define yy second

void solve(){
    int n;
    cin >> n;
    vector<pair<double, double>> po(n + 1);
    // vector<pair<ll, ll>> po(n + 1);
    rep(i, 1, n) cin >> po[i].xx >> po[i].yy;
    ll ans = 0;
    rep(i, 1, n - 1){
        rep(j, i + 1, n){
            int cnt1 = 0, cnt2 = 0;
            if(po[j].xx == po[i].xx){
                rep(k, 1, n){
                    if(po[k].xx < po[j].xx) cnt1++;
                    else if(po[k].xx > po[j].xx) cnt2++;
                }
            }else{
                double k = (double)(po[i].yy - po[j].yy) / (po[i].xx - po[j].xx);
                double b = po[i].yy - k * po[i].xx;
                rep(k, 1, n){ 
                    if(po[k].yy > k * po[k].xx + b) cnt1++;
                    else if(po[k].yy > k * po[k].xx + b) cnt2++;
                    // if(((po[j].xx - po[i].xx) * po[k].yy + (po[j].yy - po[i].yy) * po[i].xx) > (po[j].xx - po[i].xx) * po[i].yy + (po[i].yy - po[j].yy) * po[k].xx) cnt1++;
                    //else if(po[k].yy - k * po[k].xx - b < 0) cnt2++;
                    // else if(((po[j].xx - po[i].xx) * po[k].yy + (po[j].yy - po[i].yy) * po[i].xx) < (po[j].xx - po[i].xx) * po[i].yy + (po[i].yy - po[j].yy) * po[k].xx) cnt2++;
                }
            }
            
            //cout << i << " " << j <<  " : " << cnt1 << " " << cnt2 << endl;
            if(cnt1 == cnt2){
                ans++;
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}