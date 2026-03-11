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

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 998244353;       // 注意判断 INF 具体的可能值
int a[10];
int g[4][4];
inline void solve(){
    rep(i, 1, 3){
        rep(j, 1, 3){
            cin >> g[i][j];
            a[g[i][j]]++;
        }
    }
    rep(i, 1, 9){
        if(a[i] != 1){
            cout << "NO";
            return;
        }
    }
    rep(i, 1, 3){
        int sum = 0;
        rep(j, 1, 3){
            sum += g[i][j];
        }
        if(sum != 15){
            cout << "NO" << endl;
            return;
        }
    }
    rep(j, 1, 3){
        int sum = 0;
        rep(i, 1, 3){
            sum += g[i][j];
        }
        if(sum != 15){
            cout << "NO" << endl;
            return;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    sum1 += (g[1][1] + g[2][2] + g[3][3]);
    if(sum1 != 15){
        cout << "NO";
        return;
    }
    sum2 += (g[1][3] + g[2][2] + g[3][1]);
    if(sum2 != 15){
        cout << "NO";
        return;
    }
    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}