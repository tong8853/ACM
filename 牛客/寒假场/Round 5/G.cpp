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
    // int x = 0;
    // string s;cin >> s;
    // vi a(101);
    // int n = 100;
    // rep(i, 1, n){
    //     a[i] = s[i - 1] - '0';
    // }
    // rep(i, 1, 100){
    //     if(a[i] == 0){
    //         x = 3 - x;
    //         cout << x;
    //     }else if(a[i] == 1){
    //         if(x == 3 || x == 1) x = 4 - x;
    //         cout << x;
    //     }else if(a[i] == 2){
    //         if(x == 0 || x == 1) x = 1 - x;
    //         else if(x == 2 || x == 3) x = 5 - x;
    //         cout << x;
    //     }else if(a[i] == 3){
    //         if(x == 0 || x == 2) x = 2 - x;
    //         cout << x;
    //     }else if(a[i] == 4){
    //         x = (x + 1) % 4;
    //         cout << x;
    //     }else{
    //         x = (x + 3) % 4;
    //         cout << x;
    //     }
    // }
    cout << "3132333010010310230010130130330130312312210210010321300120122322322101123223211001003013030031210332";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}