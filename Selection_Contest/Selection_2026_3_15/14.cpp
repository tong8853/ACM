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

const int N = 1e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的

vector<PII> T;
bool cmp(PII x, PII y){
    if(x.ss != y.ss) return x.ss < y.ss;
    return x.ff < y.ff;
}

inline void solve(){
    int n;cin >> n;
    int tmp = n;
    while(tmp--){
        int h1, h2, m1, m2, s1, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int t1 = h1 * 3600 + m1 * 60 + s1;
        int t2 = h2 * 3600 + m2 * 60 + s2;
        T.push_back({t1, t2});
        //cout << t1 << " " << t2 << endl;
    }
    int L = 0;
    int R = 0;
    int maxx = 0;
    sort(all(T), cmp);
    while(L < n && R < n){
        int x = 0;
        //cout << x << endl;
        while(T[L].ff <= T[R].ss && L < n && R < n){
            x++;
            L++;
        }
        //cout << x << endl;
        maxx = max(x, maxx);
        if(L == n) break;
        x--;
        R++;
    }
    cout << maxx << endl;
}

int main() {
    int T = 1;//cin >> T;
    while(T--)solve();
}