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
    string s;
    vector<string> a;
    while(cin >> s && s != "."){
        a.push_back(s);
    }
    if(a.size() < 2){
        cout << "Momo... No one is for you ...";
    }else if(a.size() >= 14){
        cout << a[1] << " and " << a[13] << " are inviting you to dinner...";
    }else{
        cout << a[1] << " is the only one for you...";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}