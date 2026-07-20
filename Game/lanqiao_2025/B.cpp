#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<utility>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using PII = pair<int, int>;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define rep2(i, a, b) for(int i = (a); i >= (b); --i)
#define endl '\n'

const int mod = 1e9 + 7;
ll dp[2026][2][2];
void solve(void){
	//2025 = 5 ^ 2 * 3 ^ 4
	dp[1][0][0] = 8;
	dp[1][0][1] = 4;
	dp[1][1][0] = 2;
	dp[1][1][1] = 1;
	rep(i, 2, 2025){
		dp[i][0][0] = (dp[i - 1][1][1] << 3) % mod;
		dp[i][0][1] = ((dp[i - 1][1][0] + dp[i - 1][1][1]) << 2) % mod;
		dp[i][1][0] = ((dp[i - 1][0][1] + dp[i - 1][1][1]) << 1) % mod;
		dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0] + dp[i - 1][1][1]) % mod;
	}
	cout << (dp[2025][0][0] + dp[2025][0][1] + dp[2025][1][0] + dp[2025][1][1]) % mod << endl;
	
	cout << 147479008 << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}
