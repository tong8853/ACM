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

char g[1005][1005];
int dist[1005][1005];
PII dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


inline void solve(){
    int n, m, x1, y1, x2, y2;cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    queue<PII> q;
    memset(dist, -1, sizeof(dist));
    dist[x1][y1] = 0;
    q.push({x1, y1});
    while(!q.empty()){
        PII point = q.front();
        q.pop();
        int x = point.ff;
        int y = point.ss;
        if(x == x2 && y == y2){
            cout << dist[x][y] << endl;
            return;
        }
        rep(i, 0, 3){
            int nx = x + dxy[i].ff;
            int ny = y + dxy[i].ss;

            if(nx >= 1 && nx <= n && ny >=1 && ny <= m && dist[nx][ny] == -1 && g[nx][ny] == '.'){
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}