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
    ll n;
    cin >> n;
    if((int)sqrt(n) == sqrt(n)){
        cout << 0 << endl << endl;
        return;
    }

    ll a = -1, b = -1;
    rep2(i, (int)sqrt(n), 1){
        if(n % i == 0){
            a = i;
            break;
        }
    }
    b = n / a;
    int m = 0;
    vi ans;
    while(a != b){
        if(a > b) swap(a, b);

        a += a;
        ans.push_back(a);
        m++;
    }
    cout << m << endl;
    rep(i, 0, (int)ans.size() - 1) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}