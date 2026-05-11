#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)

void solve() {
    int n, k;
    cin >> n >> k;
    string a; cin >> a;
    int ca = 0;
    for(char c : a) if(c == '1') ca++;
    
    int ans = -1;
    int mod = 1 << k;
    
    //枚举B中1的个数
    rep(i, 0, k){
	    int b = (ca + i)% mod;
        int tmp = b;
        int cnt = 0;
        while(tmp > 0){
            if(tmp & 1) cnt++;
            tmp >>= 1;
        }
	    if(i == cnt){
			if(ans == -1 || b < ans) ans = b;
	    }
	}
	  
    if(ans == -1) cout << "None" << endl;
    else{
    rep2(i, k - 1, 0){
        cout << ((ans >> i) & 1);
    }
    cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}