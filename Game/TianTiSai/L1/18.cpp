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
    int h, m;
    scanf("%d:%d", &h, &m);
    if(h < 12 || (h == 12 && m == 0)){
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    }else{
        // 计算敲钟次数
        int count = h - 12;
        if (m > 0) count++; 
        
        for (int i = 0; i < count; ++i) {
            cout << "Dang";
        }
        cout << endl; // 敲完后记得换行
    }
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--)solve();
}