#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 505, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值

ll a[N][N], s[N][N];
int n, m, q;

int dx[] = {0, 0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1};
int dy[] = {0, 1, -1, 0, 0, 2, -2, 0, 0, 1, -1, 1, -1};

inline void solve(){
    cin >> n >> m >> q;
    pair<int, int> pos = {0, 0};
    ll maxx = 0;
    rep(i, 1, n)rep(j, 1, m){
        cin >> a[i][j];
    }
    rep(i, 1, n)rep(j, 1, m)rep(k, 0, 12){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m){
            s[nx][ny] += a[i][j];
            if(s[nx][ny] > maxx){
                pos = {nx, ny};
                maxx = s[nx][ny];
            }
        }
    }
    while(q--){
        int x, y;cin >> x >> y;
        int d;cin >> d;
        rep(i, 0, 12){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && nx <= n && ny > 0 && ny <= m){
                s[nx][ny] += d;
                if(s[nx][ny] > maxx){
                    pos = {nx, ny};
                    maxx = s[nx][ny];
                }
            }
        }
        cout << pos.ff << " " << pos.ss << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}