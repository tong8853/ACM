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
    int a, b, n;cin >> a >> b >> n;
    int cnta = 0, cntb = 0;
    rep(i, 1, n){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        if((x2 == (x1 + y1)) ^ (y2 == x1 + y1)){
            if(x2 == (x1 + y1)){
                if(cnta == a){
                    cout << 'A' << endl;
                    cout << cntb;
                    return;
                }
                cnta++;
            }else{
                if(cntb == b){
                    cout << 'B' << endl;
                    cout << cnta;
                    return;
                }
                cntb++;
            }
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}