#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve(){
    vi a;
    int x;
    while(cin >> x){
        a.push_back(x);
    }
    int n = a.size();
    vi num(n);
    auto dfs = [&](auto self, int i) -> int{
        if(i < 0) return 0;
        if(num[i] != 0) return num[i];
        int res = max(self(self, i - 2) + a[i], self(self, i - 1));
        num[i] = res;
        return res;
    };
    cout << dfs(dfs, n - 1) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}