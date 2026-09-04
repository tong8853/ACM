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
    int n;
    cin >> n;
    deque<int> a, b;
    rep(i, 1, n){
        if(i % 2){
            a.push_back(i);
            b.push_front(i);
        }else{
            a.push_front(i);
            b.push_back(i);
        }
    }
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
    for(auto x : b){
        cout << x << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}