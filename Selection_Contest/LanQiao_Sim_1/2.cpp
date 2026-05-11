#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5;
const ll p = 998244353;

inline void solve(){
    int ans = 0;
    vi a;
    map<int, int> mp;
    int x;
    while(cin >> x && x != -1) a.push_back(x);
    rep(i, 0, a.size() - 1){
        mp[a[i]]++;
        if(mp[a[i]] >= 2){
            ans = a[i];
            break;
        }
    }
    if(ans) cout << ans << endl;
    else cout << "NONE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}