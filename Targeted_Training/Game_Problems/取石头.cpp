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
    vi move = {1, 3, 9};
    vi sg(101);
    sg[0] = 0;
    rep(i, 1, 100){
        vi mex;
        rep(j, 0, 2){
            if(i - move[j] >= 0){
                mex.push_back(sg[i - move[j]]);
            }
        }
        int mexx = 0;
        for(auto x : mex){
            if(x == mexx) mexx++;
            else break;
        }
        sg[i] = mexx;
    }
    int x, y;
    while(cin >> x && cin >> y){
        cout << ((sg[x] ^ sg[y]) ? "win" : "lose") << endl;
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