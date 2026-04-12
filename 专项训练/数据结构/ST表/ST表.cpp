#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = log2(maxn) + 10;
int n, q, a[maxn], st[maxn][maxm];
namespace quick {
	inline int read() {
		int x = 0, f = 1; char ch = getchar();
		while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
		while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
		return x * f;
	}
}
void st_build() {
	for (int i = 1; i <= n; i++) st[i][0] = a[i];
	int t = log2(n);
	for (int j = 1; j <= t; j++) 
		for (int i = 1; i <= n - (1 << j) + 1; i++) 
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); 
}
int st_query(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	n = quick::read();
	q = quick::read();
	for (int i = 1; i <= n; i++) a[i] = quick::read();
	st_build();
	while (q--) {
		int l = quick::read(), r = quick::read(); 
		cout << st_query(l, r) << "\n";
	}
	return 0;
}
