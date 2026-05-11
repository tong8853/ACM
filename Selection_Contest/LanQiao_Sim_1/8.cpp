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
    vi a;
    while(1){
        int x;cin >> x;
        if(x != -1) a.push_back(x);
        else break;
    }
    int n = a.size();
    rep(j, 3, n - 3){
        rep(i, 0, j - 3){
            if(a[j] == a[i] && a[j + 1] == a[i + 1] && a[j + 2] == a[i + 2]){
                cout << a[j] << " " << a[j + 1] << " " << a[j + 2] << endl;
                return;
            }
        }
    }
    cout << "NONE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}