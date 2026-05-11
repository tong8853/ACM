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
const int N = 1e4+5;
const ll p = 998244353;

struct e{
    int ne, v, w;
}e[N];//存所有的边

int h[N];//以u为起点的上一次加入的边
int id = 0;//id动态记录每一个边的序号

void adde(int v, int u, int w){
    id++;
    e[id].v = v, e[id].w = w;
    e[id].ne = h[u]; //因为是头插法，这里用ne表示
    h[u] = id;
}

int n, m;

inline void solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int u, v, w;cin >> u >> v >> w;
        adde(u, v, w);
        //adde(v, u, w) 无向图的时候建两次有向即可
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}