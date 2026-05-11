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
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = (m - (a[i] + (i + 1)) % m) % m;
    }
    sort(b.begin(), b.end());

    
    if (m > n){
        cout << "YES" << endl;
    }else{
        bool ok = true;
        int cur = 1;
        
        vi cnt(m, 0);
        for(ll x : b) cnt[x]++;
        
        for(int i=0; i<m; ++i){
            if(cnt[i] == 0){
                ok = true; 
                break;
            }
            ok = false;
        }
        
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}