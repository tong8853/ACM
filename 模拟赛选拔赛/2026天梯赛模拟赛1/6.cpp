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
    int x;cin >> x;
    if(x % 3 == 0){
        int y = x / 3;
        rep(i, 1, 1024){
            if(y == i * i * i){
                cout << x << " is a triple flower" << endl;
                return;
            }
        }
    }
    if(x % 2 == 0){
        int y = x / 2;
        rep(i, 1, 1024 * 32){
            if(y == i * i){
                cout << x << " is a double flower" << endl;
                return;
            }
        }
    }
    cout << x << " is " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}