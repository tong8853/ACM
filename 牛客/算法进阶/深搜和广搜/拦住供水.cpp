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

int n, m;
char g[505][505];

void dfs(int x, int y){ //标记（x, y）为被蔓延
    if(x < 1 || x > n || y < 1 || y > m || g[x][y] == '*') return;

    g[x][y] = '*';

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x,  y + 1);
}


inline void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >>g[i][j];

    rep(i, 1, n){
        dfs(i, 1);
        dfs(i, m);
    }
    rep(j, 1, m){
        dfs(1, j);
        dfs(n, j);
    }
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, m){
        if(g[i][j] == '0') cnt++; 
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}