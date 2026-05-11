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
    int n;
    cin >> n;
    vi a(2 * n);
    int pos1 = -1, pos2 = -1;
    rep(i, 0, 2 * n - 1){//找0的位置
        cin >> a[i];
        if(a[i] == 0){
            if(pos1 == -1) pos1 = i;
            else pos2 = i;
        }
    }
    vi vis(n);  
    auto cal_mex = [&](int l, int r){
        //清空上一次记录
        rep(i, 0, n - 1) vis[i] = 0;

        while(l >= 0 && r < 2 * n && a[l] == a[r]){
            vis[a[l]] = 1;
            l--, r++;
        }

        rep(i, 0, n - 1){
            if(!vis[i]) return i;
        }
        return n;
    };

    int ans = max({
        cal_mex(pos1, pos1),
        cal_mex(pos2, pos2),
        cal_mex((pos1 + pos2) / 2, (pos1 + pos2 + 1) / 2)
    });
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