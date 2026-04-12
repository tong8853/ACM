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
const ll INF = 1e15;       // 注意判断 INF 具体的可能值

int a[15][15];
int b[15][15];
bool ok[15][15];
PII dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<PII> path;
int n, m, p;

inline void solve(){
    cin >> n >> m >> p;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) rep(j, 1, m) cin >> b[j][j];//b没有用
    //对1,1进行一次BFS
    queue<PII> q;
    stack<PII> st;
    q.push({1, 1});
    ok[1][1] = 1;
    while(!q.empty()){
        PII point = q.front();
        q.pop();
        int x = point.ff;
        int y = point.ss;
        rep(i, 0, 3){
            int nx = x + dxy[i].ff;
            int ny = y + dxy[i].ss;

            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !ok[nx][ny]){
                ok[nx][ny] = 1;
                
            }
        }
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}