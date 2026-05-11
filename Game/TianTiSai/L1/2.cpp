#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define pb push_back    
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

int a[505];
inline void solve(){
    int n;cin >> n;
    char c;cin >> c;
    int h = (int)(sqrt(double(n + 1) / 2));
    per(i, h, 1){
        rep(j, 1, h - i) cout << " ";
        rep(j, 1, 2 * i - 1) cout << c;
        cout << endl;
    }
    rep(i, 2, h){
        rep(j, 1, h - i) cout << " ";
        rep(j, 1, 2 * i - 1) cout << c;
        cout << endl;
    }
    cout << n - (2 * h * h - 1);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}