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
    deque<string> a, b;
    int n;cin >> n;
    vi c(n + 1);
    rep(i, 1, n){
        int x;
        string s;
        cin >> x >> s;
        c[i] = x;
        if(x == 0) a.push_back(s);
        else b.push_back(s);
    }
    int id = 0;
    rep(i, 1, n / 2){
        if(c[i] == 0){
            cout << a.front() << " " << b.back() << endl;
            a.pop_front(), b.pop_back();
        }else{
            cout << b.front() << " " << a.back() << endl;
            b.pop_front(), a.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}