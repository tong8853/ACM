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

int n;
char g[1005][1005];
bool ok[1005][1005];
PII dxy[] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};

inline void solve(){
    cin >> n;
    rep(i, 1, n) rep(j, 1,n) cin >> g[i][j];
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, n){
        if(g[i][j] == '#' && !ok[i][j]){
            bool flag = true; //假设该区域会被完全淹没
            ok[i][j] = 1;
            queue<PII> q;
            q.push({i, j});
            while(!q.empty()){
                PII point = q.front();
                q.pop();
                int x = point.ff;
                int y = point.ss;
                int sum = 0;
                rep(k, 0, 3){
                    int nx = x + dxy[k].ff;
                    int ny = y + dxy[k].ss;
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && g[nx][ny] == '#'){
                        sum++;
                        if(!ok[nx][ny]){
                            q.push({nx, ny});
                            ok[nx][ny] = 1;
                        }
                    }
                }
                if(sum == 4) flag = false;
            }
            if(flag) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}