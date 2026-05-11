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

inline void solve(){
    int n;cin >> n;
    vi a(n);read(a, 0, n - 1);
    vi ans;
    for(auto &x : a){
        auto pos = lower_bound(all(ans), x) - ans.begin();
        if(pos == ans.size()) ans.push_back(x);
        else ans[pos] = x;
    }
    cout << ans.size() << endl;
}

int main() {
    int T = 1;//cin >> T;
    while(T--)solve();
}