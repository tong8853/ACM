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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m + 1);
    rep(i, 1, m){
        cin >> a[i].ff >> a[i].ss;
    }

    auto find = [&](int x) -> vi{ //固定x返回配对的y的所有可能
        vi mis;
        rep(i, 1, m){
            if(x != a[i].ff && x != a[i].ss) mis.push_back(i); 
        }

        vi res;

        if(mis.size() == 0){
            rep(y, 1, n){
                if(y != x) res.push_back(y); 
            }
            return res;
        }

        //如果x有漏的，则y一定来自第一场漏掉的比赛
        int fmis = mis[0];
        int cand1 = a[fmis].ff, cand2 = a[fmis].ss;
        vi cands;
        cands.push_back(cand1), cands.push_back(cand2);

        for(int cand : cands){
            bool ok = 1;
            for(int misid : mis){
                if(cand != a[misid].ff && cand != a[misid].ss){
                    ok = 0;
                    break;
                }
            }

            if(ok) res.push_back(cand);
        }
        return res;
    };

    vi pA1 = find(a[1].ff);
    vi pB1 = find(a[1].ss);

    ll ans = 0;
    ans += pA1.size(), ans += pB1.size();
    for(int y : pA1){
        if(y == a[1].ss) ans--;
    }

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