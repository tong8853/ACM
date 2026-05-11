#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define pb push_back    
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 1e5+5;
const ll p = 998244353;

int a[N];
inline void solve(){
    int n;cin >> n;
    rep(i, 1, n) cin >> a[i];
    int maxx = *max_element(a+1, a+n+1);
    vi count(maxx + 1, 0);
    rep(i, 1, n) count[a[i]]++;
    per(i, maxx, 1){ //从最大的可能的gcd刚下检验
        int cnt = 0;
        for(int j = i; j <= maxx; j +=i){
            cnt += count[j];
        }
        if(cnt >= 3){
            vi ans;
            rep(j, 1, n){
                if(a[j] % i == 0){
                    ans.push_back(a[j]);
                }
            }
            sort(all(ans));
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}