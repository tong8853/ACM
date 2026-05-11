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

map<int, int> mp;

inline void solve(){
    int a, b;cin >> a >> b;
    int maxx = 0;
    rep(i, a, b){
        int tmp = i;
        while(tmp >= 10){
            int tmp2 = tmp;
            tmp = 1;
            while(tmp2){
                tmp *= (tmp2 % 10);
                tmp2 /= 10;
            }
            mp[i]++;
        }
    }
    rep(i, a, b) maxx = max(maxx, mp[i]);
    cout << maxx << endl;
    vi ans;
    rep(i, a, b) if(mp[i] == maxx) ans.push_back(i);
    rep(i, 0, ans.size() - 1){
        if(i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}