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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

ll dig_he(int x){
    ll ans = 0;
    while(x != 0){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

inline void solve(){
    ll a, b;cin >> a >> b;
    ll sa = dig_he(a);
    ll sb = dig_he(b);
    if(a % sb == 0 && b % sa == 0 || a % sb != 0 && b % sa != 0){
        cout << (a > b ? "A" : "B") << endl;
        return;
    }
    if(a % sb == 0){
        cout << "A" << endl;
        return;
    }
    if(b % sa == 0){
        cout << "B" << endl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}