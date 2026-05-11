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
    int na, nb, q;
    cin >> na >> nb >> q;
    vi a(na + 1), b(nb + 1);
    rep(i, 1, na) cin >> a[i];
    rep(i, 1, nb) cin >> b[i];
    sort(a.begin()+1, a.end()), sort(b.begin()+1, b.end());
    int maxk = max(a[na], b[nb]);
    vi hashA(maxk + 1, 0), hashB(maxk + 1, 0);
    vi ansA(maxk + 1, 0), ansB(maxk + 1, 0);
    rep(i, 1, na) hashA[a[i]] = 1;
    rep(i, 1, nb) hashB[b[i]] = 1;
    rep(k, 1, maxk){
        for(int j = k; j <= maxk; j += k){
            if(hashA[j]) ansA[k] = max(ansA[k], j);
            if(hashB[j]) ansB[k] = max(ansB[k], j);
        }
    }

    while(q--){
        int k;
        cin >> k;
        if(k > maxk){
            cout << 'Z' << endl;
            continue;
        }
        if(ansA[k] >= ansB[k] && ansA[k] != 0) cout << 'X' << endl;
        else cout << 'Z' << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}