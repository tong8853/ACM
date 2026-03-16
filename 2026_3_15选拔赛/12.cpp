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

int peng[105];
int di[105][105];

int find(int x){
    if(peng[x] == x) return x;
    else return peng[x] = find(peng[x]); 
}

inline void solve(){
    int n, m, k;cin >> n >> m >> k;
    rep(i, 1, n) peng[i] = i;
    while(m--){
        int x, y, op;cin >> x >> y >> op;
        if(op == 1){
            x = find(x), y = find(y);
            peng[x] = y;
        }else{
            di[x][y] = 1;
            di[y][x] = 1;
        }
    }
    while(k--){
        int x, y;cin >> x >> y;
        if(find(x) == find(y)){
            if(!di[x][y]) cout << "No problem" << endl;
            else cout << "OK but..." << endl;
        }else{
            if(!di[x][y]) cout << "OK" << endl;
            else cout << "No way" << endl;
        }
    }
}

//No problem
//OK
//OK but...
//No way

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}