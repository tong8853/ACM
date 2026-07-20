#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define ff first
#define ss second

void solve(){
    
    
    ll ans = -1;
    int n;
    cin >> n;
    vi x(n + 1);
    vi y(n + 1);
    map<pair<ll, ll>, vector<pair<ll, ll>>> v;
    rep(i, 1, n){
        cin >> x[i] >> y[i]; 
    }
    auto cal = [&](ll dx1, ll dy1, ll dx2, ll dy2)->ll{
        return llabs(dx1 * dy2 - dx2 * dy1) / 2;
    };

    auto check = [&](ll i, ll j, ll k)->bool{
        return (y[k] - y[i]) * (x[j] - x[i])== (y[j] - y[i]) * (x[k] - x[i]); 
    };
    //按线段中点存储，如果中点相同就存在一起
    rep(i, 1, n - 1){
        rep(j, i + 1, n){
            v[{x[i] + x[j], y[i] + y[j]}].push_back({i, j});
        }
    }
    for(auto &[zhong, p] : v){
        rep(i, 0, (int)p.size() - 1){
            rep(j, i + 1, (int)p.size() - 1){
                ll id1 = p[i].ff, id2 = p[i].ss, id3 = p[j].ff, id4 = p[j].ss;
                ll dx1 = x[id1] - x[id2];
                ll dy1 = y[id1] - y[id2];
                ll dx2 = x[id3] - x[id4];
                ll dy2 = y[id3] - y[id4];
                ll f1 = cal(dx1, dy1, dx2, dy2);
                if(!(check(id1, id2, id3) || check(id1, id2, id4) || check(id2, id3, id4))){
                    ans = max(ans, f1);
                }
            }
        }
    }

    if(ans == -1) cout << -1 << endl;
    else cout << ans << ".0" << endl;   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}