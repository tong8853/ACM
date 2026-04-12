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

inline void solve(){
    int q;cin >> q;
    deque<int> de;
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int x;cin >> x;
            de.push_front(x);
        }else if(op == 2){
            int x;cin >> x;
            de.push_back(x);
        }else if(op == 3){
            cout << de.front() << endl;
            de.pop_front();
        }else{
            cout << de.back() << endl;
            de.pop_back();
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}