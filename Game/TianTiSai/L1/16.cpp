#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

//只检查前17位是否全为数字且最后1位校验码计算准确
void solve(){
    int n;
    cin >> n;
    vector<string> ans;
    char yin[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int k[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    rep(i, 1, n){
        string s;cin >> s;
        ll quan = 0;
        int pos = -1;
        rep(j, 0, 16){
            if(s[j] == 'X'){
                ans.push_back(s);
                pos = j;
                break;
            }
            quan += (s[j] - '0') * k[j];
        }
        if(s[pos] == 'X') continue;
        ll z = quan % 11;
        char x = yin[z];
        if(x != s[17]){
            //cout << x << endl;
            ans.push_back(s);
        }
    }
    if(ans.empty()) cout << "All passed";
    else{
        for(auto &x : ans){
            cout << x << endl;
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