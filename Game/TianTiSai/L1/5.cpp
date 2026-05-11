#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct node{
    string s;
    int y;
};

void solve(){
    int n;cin >> n;
    vector<node> a(n + 1);
    rep(i, 1, n){
        string s;cin >> s;
        ll id, y;cin >> id >> y;
        a[id] = {s, y}; 
    }
    int q;cin >> q;
    while(q--){
        int id;cin >> id;
        cout << a[id].s << " " << a[id].y << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}