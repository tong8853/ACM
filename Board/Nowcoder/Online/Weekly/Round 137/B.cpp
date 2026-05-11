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

const int N = 2e5+5;
const ll p = 998244353;

inline void solve(){
    bool ok = 1;
    int n;cin >> n;
    deque<char> d;
    rep(i, 1, n){
        char x;cin >> x;
        if(x == '!'){
            ok = !ok;
        }else if(x == '-'){
            if(!d.empty()){
                if(ok) d.pop_back();
                else d.pop_front();
            }
        }else{
            if(ok) d.push_back(x);
            else d.push_front(x);
        }
    }
    if(d.empty()) cout << "Empty" << endl;
    else{
        for(auto &x : d) cout << x;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}