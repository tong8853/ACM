#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;	

int n, m;


void solve(){
    cin >> n;
    vector<int> a(n), ans(n + 1, 0);
    for (int &x : a) cin >> x;
    
    // 枚举 i 作为截取的子段的末段
    stack<int> st;
    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && (i == n || a[st.top()] > a[i])) {
            int x = st.top(); st.pop();
            int len = st.empty() ? i : i - st.top() - 1; 
            ans[len] = max(ans[len], a[x]);       
        }
        st.push(i);
    }
    for (int i = n - 1; i >= 1; --i) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}