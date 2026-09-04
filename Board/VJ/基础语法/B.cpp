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
    int a, b, c;//包装的个数
	int n, x1, x2, y1, y2, z1, z2;
	cin >> n >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
	a = (int)ceil(n * 1.0 / x1), b = (int)ceil(n * 1.0 / y1), c = (int)ceil(n * 1.0 / z1);
	int m1 = a * x2, m2 = b * y2, m3 = c * z2;
	cout << min({m1, m2, m3}) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}