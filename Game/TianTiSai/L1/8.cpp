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
    int a, b, sum = 0, cnt = 0;
    cin >> a >> b;
    rep(i, a, b){
        cout << setw(5) << i;
        cnt++;
        sum += i;
        if(cnt % 5 == 0 || i == b) cout << endl;
    }
    cout << "Sum = " << sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}