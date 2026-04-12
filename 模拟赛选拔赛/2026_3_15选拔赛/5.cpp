/*
 * 天梯赛选拔赛
 */

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
vi a;

inline void solve(){
    vi cai;
    rep(i, 0, n - 1){
        int x;cin >> x;
        cai.push_back(x);
    }
    bool ok = true;
    ll sum = 0;
    rep(i, 0, n - 1){
        if(cai[i] == 0) continue;
        sum += cai[i];
        if(a[i] != cai[i]){
            ok = false;
            break;
        }
    }
    if(sum != 0 && ok) cout << "Da Jiang!!!" << endl;
    else cout << "Ai Ya" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n){
        int x;cin >> x;
        a.push_back(x);
    }
    int T = 1;cin >> T;
    while(T--)solve();
}