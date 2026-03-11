#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

inline void solve(){
    int a, b;cin >> a >> b;
    if(a < b){//隔板
        int pt = a + 1;
        int base = b / pt;
        int t = b % pt;
        rep(i, 1, pt){
            int cnt = base + (i <= t ? 1 : 0);
            rep(j, 1, cnt) cout << 1;
            if (i <= a) cout << 0;
        }
        cout << endl;
    }else{
        int pt = b + 1;
        int base = a / pt;
        int t = a % pt;
        rep(i, 1, pt){
            int cnt = base + (i <= t ? 1 : 0);
            rep(j, 1, cnt) cout << 0;
            if (i <= b) cout << 1;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}