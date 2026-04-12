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
char g[1005][1005];
PII dxy[] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};

inline void solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, m){
        if(g[i][j] == '.'){
            queue<PII> q;
            q.push({i, j});
            int cnt_di = 1;
            int minx = i, miny = j, maxx = i, maxy = j;
            g[i][j] = '*';
            while(!q.empty()){
                PII point = q.front();
                q.pop();
                int x = point.ff;
                int y = point.ss;
                rep(k, 0, 3){
                    int nx = x + dxy[k].ff;
                    int ny = y + dxy[k].ss;
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] == '.'){
                        q.push({nx, ny});
                        minx = min(minx, nx);
                        miny = min(miny, ny);
                        maxx = max(maxx, nx);
                        maxy = max(maxy, ny);
                        cnt_di++;
                        g[nx][ny] = '*';
                    }
                }
            }
            //判断全下来的地是不是长方形
            int cnt_ju = (maxx - minx + 1) * (maxy - miny + 1);
            if(cnt_di == cnt_ju) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}