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
    int n;cin >> n;
    char c;cin >> c;
    string s, kong;
    //cin.ignore() // 跳过缓冲区中当前的一个字符（即那个换行符）
    getline(cin, kong);//吃掉上一行的换行符
    getline(cin, s);
    if(n < s.size()){
        rep(i, s.size() - n, s.size() - 1) cout << s[i];
    }else{
        rep(i, 1, (int)(n - s.size())) cout << c;
        rep(i, 0, s.size() - 1) cout << s[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}