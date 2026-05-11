#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

//如果某个数a[i]是一个子段的最小值，那么这个子段最长能有多长？

void solve(){
    int n;
    cin >> n;
    vi a(n + 1), ans(n + 1);
    rep(i, 1, n) cin >> a[i];
    
    stack<int> st;
    rep(i, 1, n + 1){
        while(!st.empty() && (a[i] < a[st.top()] || i == n + 1)){//说明st.top找到了右边界
            int x = st.top(); st.pop();
            int len = st.empty() ? (i - 1) : i - st.top() - 1;
            ans[len] = max(ans[len], a[x]);
        }
        st.push(i);
    }
    rep2(i, n - 1, 1){
        ans[i] = max(ans[i + 1], ans[i]);
    }
    rep(i, 1, n) cout << ans[i] << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}