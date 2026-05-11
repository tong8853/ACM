#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5+7;
int n;
vi v;
bool vis[N];

int cal(int l, int r){
    //清空上一次的记录
    rep(i, 0, n) vis[i] = 0;

    while(l >= 0 && r < 2 * n && v[l] == v[r]){
        if(v[l] <= n) vis[v[l]] = true;
        l--, r++;
    }
    
    rep(i, 0, n){
        if(!vis[i]) return i;
    }
    return n + 1;
}

void solve(){
    cin >> n;
    v.assign(2*n, 0);
    int pos1 = -1, pos2 = -1;
    rep(i, 0, 2*n-1){
        cin >> v[i];
        if(!v[i]){
            if(pos1 == -1) pos1 = i;
            else pos2 = i;
        }
    }

    int ans = max({
        cal(pos1, pos1),
        cal(pos2, pos2),
        cal((pos1 + pos2) / 2, (pos1 + pos2 + 1) / 2)
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