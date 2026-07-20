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
    int n, x, s;
    cin >> n >> x >> s;
    string S;
    cin >> S;

    auto cal = [&](int m)->ll{
        ll t = 0, ans = 0; //t是已用桌子数量
        for(char c: S){
            if(c == 'I'){
                if(t < x){
                    t++;
                    ans++;
                }
            }else if(c == 'E'){
                if(ans < t * s) ans++;
            }else{
                if(m-- > 0){
                    if(t < x){
                        t++;
                        ans++;
                    }
                }else{
                    if(ans < t * s) ans++;
                }
            }
        }
        return ans;
    };

    int cnt = 0;
    for(char c : S) if(c == 'A') cnt++;

    ll ans = 0;
    rep(i, 0, cnt) ans = max(ans, cal(i)); //枚举中间者A的角色划分，i个A被当成内向者

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}