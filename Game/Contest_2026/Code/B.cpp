#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;

deque<string> his, fwd;
string now = "home";
int cap;

void add(deque<string>& q, string s) {
    if (q.size() >= cap) q.pop_front();
    q.push_back(s);
}

void solve(){
    cin >> cap;
    string op, url;
    while (cin >> op) {
        if (op == "close") break;
        
        if (op == "home") {
            if (now != "home"){
                add(his, now);
                now = "home";
                fwd.clear();
            }
        } else if (op == "visit") {
            cin >> url;
            if (url != now){
                add(his, now);
                now = url;
                fwd.clear();
            }

        } else if (op == "forward") {
            if (!fwd.empty()){
                add(his, now);
                now = fwd.back();
                fwd.pop_back();
            }
        } else if (op == "return") {
            if (!his.empty()){
                add(fwd, now);
                now = his.back();
                his.pop_back();
            }
        } else if (op == "now"){
            cout << now << endl;
        }
    }
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}