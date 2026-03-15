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
const int M = 1e6+5;
const ll INF = 1e15;       // 注意判断 INF 具体的可能值

inline void solve(){
    ll a, b, x;cin >> a >> b >> x;
    //先计算谁更划算
    if(3 * a <= b){
        cout << x * a << endl;
        return;
    }else{//n个b, m个a
        ll n = x / 3;
        ll m = x - n * 3;
        //刚刚好
        ll sum1 = n * b + m * a;
        ll sum2 = (n + 1) * b;
        cout << min(sum1, sum2) << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}