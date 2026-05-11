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
    set<int, greater<int>> st;
    string s;cin >> s;
    rep(i, 0, s.size() - 1){
        st.insert(s[i] - '0');
    }
    vi arr;
    for(auto &x : st){
        arr.push_back(x);
    }
    vi pos(10);
    vi index;
    rep(i, 0, arr.size() - 1){
        pos[arr[i]]  = i;
    }
    rep(i, 0, s.size()  -1){
        index.push_back(pos[s[i] - '0']);
    }
    cout << "int[] arr = new int[]{";
    rep(i, 0, arr.size() - 1){
        if(i) cout << ',';\
        cout << arr[i];
    }
    cout << "};";
    cout << endl;
    cout << "int[] index = new int[]{";
    rep(i, 0, index.size() - 1){
        if(i) cout << ',';
        cout << index[i];
    }
    cout << "};";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}