#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 2e5+5;
const ll p = 998244353;

inline void solve(){
    ll T, H, U;cin >> T >> H >> U;
    ll ans = 0;
    //T最不好了，但是U能够接纳
    if(U >= T){//T会先用完
        ans += T * 4;
        U -= T;
        T = 0;
        ans += (U + H) * 3;
    }else{//U先用完了
        ans += U * 4;
        T -= U;
        U = 0;
        //还剩T和H,优先两个T一个H
        if(T / 2 >= H){
            int T2H = H;
            ans += 7 * T2H;
            T -= 2 * T2H;
            H = 0;
            ans += 5 * (T / 2);
            if(T % 2) ans += 3;
        }else{
            int T2H = T / 2;
            ans += 7 * T2H;
            T -= 2 * T2H;
            H -= T2H;
            if(T % 2){
                ans += 5;
                H--;
                T--;
                ans += H * 3;
            }else{
                ans += H * 3;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}