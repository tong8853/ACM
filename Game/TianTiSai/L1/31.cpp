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
    double h, w1;cin >> h >> w1;
    double w2 = (h - 100) * 1.8;
    if((w1 - w2) >= (w2 * 0.1)) cout << "You are tai pang le!" << endl;
    else if((w2 - w1) >= (w2 * 0.1)) cout << "You are tai shou le!" << endl;
    else cout << "You are wan mei!" << endl; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}