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
    string s;cin >> s;
    deque<char> de;
    for(auto &c : s){
        if(!de.empty() && c == de.front()){
            de.pop_front();
        }else{
            de.push_back(c);
        }
    }
    if(de.empty()) cout << "YES" << endl;
    else{
        vi a;
        rep(i, 0, de.size() - 1){
            if(de[i] == '{' || de[i] == '}') a.push_back(2);
            else if(de[i] == '[' || de[i] == ']') a.push_back(1);
            else a.push_back(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;cin >> T;
    while(T--)solve();
}