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
    int n;cin >> n;
    deque<int> de;
    rep(i, 1, n){
        string s;cin >> s;
        if(s == "push"){
            int x;cin >> x;
            de.push_back(x);
        }else if(s == "size"){
            cout << de.size() << endl;
        }else if(s == "pop"){
            if(!de.empty()){
                de.pop_back();
            }else cout << "Empty" << endl;
        }else{
            if(de.empty()){
                cout << "Empty" << endl;   
            }else cout << de.back() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}