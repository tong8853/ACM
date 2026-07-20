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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    auto cal = [&](int m)->ll{
        ll ans = 0, t = 0;
        for(auto c : s){
            if(c == 'I'){
                if(t < a){
                    t++;
                    ans++;
                }
            }else if(c == 'E'){
                if(ans < t * b) ans++;
            }else{
                if(m-- > 0){
                    if(t < a){
                        t++;
                        ans++;
                    }   
                }else{
                    if(ans < t * b) ans++;
                }
            }
        }
        return ans;
    };

    ll l = 0, r = 0;
    for(auto c : s) if(c == 'A') r++;
    while(l < r){
        int mid = (l + r) / 2;
        int x = cal(mid), y = cal(mid + 1);
        if(x < y) l = mid + 1;
        else r = mid;
    }

    cout << cal(l) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}