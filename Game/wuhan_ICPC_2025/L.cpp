#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define ff first
#define ss second
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    map<int, int> cnt;
    rep(i, 1, n) cnt[a[i]]++;
    vector<PII> b(cnt.begin(), cnt.end());
    sort(b.begin(), b.end());
    int m = b.size(); //m是数字的种类
    map<int, PII> d;
    rep(i, 0, m - 1){
        d[b[i].ff].ff = i + 1;
        d[b[i].ff].ss = b[i].ss;
    }// d[dig].ff 大小位次    d[dig].ss 为dig的个数
    vi c(m + 1);
    rep(i, 1, m){
        c[i] = c[i - 1] + b[i - 1].ss;
    }
    int ans = 0;
    rep(i, 1, n){
        rep(j, i + 1, n){
            int z = (a[i] + a[j]) / 2;
            if(z * 2 == a[i] + a[j] && cnt[z]){
                int l = min(d[a[i]].ff, d[a[j]].ff);
                int r = max(d[a[i]].ff, d[a[j]].ff);
                int zp = d[z].ff;
                int z_cnt = d[z].ss;
                //算出z左侧右侧最多能提供多少个数
                int l_cnt = c[zp - 1] - c[l - 1];
                int r_cnt = c[r] - c[zp];
                //cout << l << r << zp << z_cnt << l_cnt << r_cnt;
                int x = 0;
                if(l == r && r == zp){
                    x = z_cnt;
                }else{
                    if(l_cnt == r_cnt){
                        x = l_cnt + r_cnt + z_cnt;
                    }else if(l_cnt < r_cnt){
                        if(r_cnt - l_cnt > z_cnt){
                            x = 2 * (l_cnt + z_cnt);
                        }else{
                            x = l_cnt + r_cnt + z_cnt;
                        }
                    }else{
                        if(l_cnt - r_cnt >= z_cnt){
                            x = 2 * (z_cnt + r_cnt)  - 1;
                        }else{
                            x= l_cnt + r_cnt + z_cnt;
                        }
                    }
                }
                
                ans = max(ans, x);
            }
        }
    }
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