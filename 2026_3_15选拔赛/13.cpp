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

const int N = 4e4+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

int peng[105];
int di[105][105];

int n, m;
char g[N][N];
PII dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];

    int cnt1 = 0;//岛数
    int cnt2 = 0;//有宝藏的岛数
    rep(i, 1, n) rep(j, 1, m){
        if(g[i][j] - '0' > 0){
            cnt1++;
            queue<PII> q;
            q.push({i, j});
            bool ok = false;
            if(g[i][j] - '0' > 1) ok = true;
            while(!q.empty()){
                PII point = q.front();
                int x = point.ff;
                int y = point.ss;
                g[x][y] = '0';
                q.pop();
                rep(i, 0, 3){
                    int nx = x + dxy[i].ff;
                    int ny = y + dxy[i].ss;
                    if(g[nx][ny] - '0' > 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                        q.push({nx, ny});
                        if(g[nx][ny] - '0' > 1) ok = true;
                        g[nx][ny] = '0';
                    }
                }
            }
            if(ok) cnt2++;
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}