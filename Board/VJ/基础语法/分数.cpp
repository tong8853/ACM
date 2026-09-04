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
    int n, k;
    cin >> n >> k;
    auto dfs = [&](auto self, int num, int timing, int now) -> int{
        if(timing == 1) return 1;

        int sum = 0;
        for(int i = now; i <= num / timing; i++){
            sum += self(self, num - i, timing - 1, i);
        }
        return sum;
    };

    cout << dfs(dfs, n, k, 1) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}