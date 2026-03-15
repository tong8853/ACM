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

int g[1005][1005];
PII dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<PII> path;
int n, m;

//题目只要求输出一条，所以不必缓存
void dfs(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m || g[x][y] == 1) return;
    g[x][y] = 1;
    path.push_back({x, y});
    if(x == n && y == m){
        for(auto &[x1, y1] : path){
            cout << "(" << x1 - 1 << "," << y1 - 1 << ")" << endl;
        }
        return;
    }
    rep(i, 0, 3){
        int nx = x + dxy[i].ff;
        int ny = y + dxy[i].ss;
        dfs(nx, ny);
    }
    //执行到这里了，说明当前点可能的四条路径都不行，这个点肯定就不行
    path.pop_back();
}

inline void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    dfs(1, 1);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}