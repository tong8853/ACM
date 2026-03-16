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

//The winner is x: P1 + P2
inline void solve(){
    ll a, b;cin >> a >> b;
    int pa = 0, pb = 0;
    rep(i, 1, 3){
        int x;cin >> x;
        if(x == 0) pa++;
        else pb++;
    }
    if(pa == 3){
        cout << "The winner is a: " << a << " + " << pa << endl;
        return; 
    }
    if(pa == 3){
        cout << "The winner is b: " << b << " + " << pb << endl;
        return; 
    }
    if(a > b){
        if(pa >= 1){
            cout << "The winner is a: " << a << " + " << pa << endl;
            return;
        }else{
            cout << "The winner is b: " << b << " + " << pb << endl;
            return;
        }
    }else{
        if(pb >= 0){
            cout << "The winner is b: " << b << " + " << pb << endl;
            return;
        }else{
            cout << "The winner is a: " << a << " + " << pa << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}