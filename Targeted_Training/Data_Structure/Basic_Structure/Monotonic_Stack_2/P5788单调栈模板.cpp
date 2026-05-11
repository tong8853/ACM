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

const int N = 3e6+5;
const ll p = 998244353;

int ans[N];
inline void solve(){
    int n;cin >> n;
    stack<PII> st;
    rep(i, 1, n){
        int x;cin >> x;
        while(!st.empty() && x > st.top().ff){
            int id = st.top().ss;
            ans[id] = i;
            st.pop();
        }

        st.push({x, i});
    }
    ans[n] = 0;
    rep(i, 1, n) cout << ans[i] << (i != n ? " " : "");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}