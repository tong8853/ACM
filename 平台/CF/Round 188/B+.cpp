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
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi s;
    rep(i, 0, n - 1){
        if(s.empty()) s.push_back(a[i]);
        else{
            if(a[i] >= s.back()){
                s.push_back(a[i]);
            }
        }
    }
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}