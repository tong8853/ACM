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
    int n;cin >> n;
    vi a(n + 1);
    read(a, 1, n);
    sort(a.begin()+1, a.begin()+n+1);
    vi ans;
    ans.push_back(a[1]);
    rep(i, 2, n){
        if(a[i] - ans[ans.size() - 1] >= ans.size()){
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}