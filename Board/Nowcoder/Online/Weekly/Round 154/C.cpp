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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c1=0, c2=0, c3=0, c4=0;
    rep(i, 0, s.size() - 1){
        if(s[i] == 'U') c1++;
        if(s[i] == 'D') c2++;
        if(s[i] == 'L') c3++;
        if(s[i] == 'R') c4++;
    } 
    if(c1 >= c2){
        int c = min(k, c2);
        c2 -= c;
        k -= c;
    }else{
        int c = min(k, c1);
        c1 -= c;
        k -= c;
    }

    if(c3 >= c4){
        int c = min(k, c4);
        c4 -= c;
        k -= c;
    }else{
        int c = min(k, c3);
        c3 -= c;
        k -= c;
    }

    int c = min(k, c1);
    c1 -= c;
    k -= c;

    c = min(k, c2);
    c2 -= c;
    k -= c;
    
    c = min(k, c3);
    c3 -= c;
    k -= c;
    
    c = min(k, c4);
    c4 -= c;
    k -= c;

    rep(i, 0, s.size() -1){
        if(s[i] == 'U' && c1 > 0){
            cout << 'U';
            c1--;
        } 
        if(s[i] == 'D' && c2 > 0){
            cout << 'D';
            c2--;
        } 
        if(s[i] == 'L' && c3 > 0){
            cout << 'L';
            c3--;
        } 
        if(s[i] == 'R' && c4 > 0){
            cout << 'R';
            c4--;
        } 
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