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
PII dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<PII> path;
int n, m;
int minx1, minx2, miny1, miny2, maxx1, maxx2, maxy1, maxy2;
PII pos_st, pos_end;

void bfs(PII pos){
    queue<PII> q;
    q.push(pos);
    bool ok = false;
    if(pos == pos_st) ok = true;
    while(!q.empty()){
        PII point = q.front();
        q.pop();
        int x = point.ff;
        int y = point.ss;
        g[x][y] = '#';
        rep(i, 0, 3){
            int nx = x + dxy[i].ff;
            int ny = y + dxy[i].ss;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] != '#'){
                q.push({nx, ny});
                g[nx][ny] = '#';
                if(ok){
                    minx1 = min(minx1, nx);
                    miny1 = min(miny1, ny);
                    maxx1 = max(maxx1, nx);
                    maxy1 = max(maxy1, ny);
                }else{
                    minx2 = min(minx2, nx);
                    miny2 = min(miny2, ny);
                    maxx2 = max(maxx2, nx);
                    maxy2 = max(maxy2, ny);
                }
            }
        }
    }
}


inline void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m){
        cin >> g[i][j];
        if(g[i][j] == 'S') pos_st = {i, j};
        if(g[i][j] == 'E') pos_end = {i, j};
    }
    //分别对起点终点做一次BFS,确定可达域
    minx1=pos_st.ff,miny1=pos_st.ss,maxx1=pos_st.ff,maxy1=pos_st.ss,minx2=pos_end.ff,miny2=pos_end.ss,maxx2=pos_end.ff,maxy2=pos_end.ss; 
    
    bfs(pos_st);
    bfs(pos_end);
    if((minx2 > maxx1 + 1 || minx1 > maxx2 + 1) && (miny1 > maxy2  + 1 || miny2 > maxy1 + 1)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}