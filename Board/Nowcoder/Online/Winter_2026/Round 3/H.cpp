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
    ll xa, ya, xb, yb;cin >> xa >> ya >> xb >> yb;
    ll A = ya - yb;
    ll B = xa * yb - xb * ya;

    if (A == 0) {
        //当直线平行于 x 轴
        if (abs(B) == 4){
            cout << fixed << setprecision(8) << 0.0 << endl;
        }else{
            cout << "no answer" << endl;
        }
    }else{
        double x = (double)(4 - B) / A;
        cout << fixed << setprecision(8) << x << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}