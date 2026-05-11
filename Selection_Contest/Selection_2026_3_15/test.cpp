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

const int N = 1e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的

inline void solve(){
    int x;
    scanf("%d", &x);
    cout << x << endl;
}

int main() {
    int T = 1;//cin >> T;
    while(T--)solve();
}