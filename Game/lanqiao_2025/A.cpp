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

const int mod = 1000000007;

void solve(void){
//	int n = 17600;
//	int cnt2 = n / 2;
//	
//	vi isp(176001, 1);
//	isp[0] = isp[1] = 0;
//	for(int i = 2; i * i <= n; i++){
//		if(isp[i]){
//			for(int j = i * i; j <= n; j += i){
//				isp[j] = 0;
//			}
//		}
//	}
//	
//	vi prime;
//	rep(i,0, 17600) if(isp[i]) prime.push_back(i);
//	ll sum = 1;
//	ll m = prime.size();
//	rep(i, 0, m - 1){
//		ll x = prime[i];
//		ll cnt = 0;
//		ll maxx = 17600;
//		while(maxx){
//			maxx /= x;
//			cnt++;
//		}
//		sum = sum * (cnt - 1) % mod;
//	}
//	cout << sum << endl;
	cout << 174149196 << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}
