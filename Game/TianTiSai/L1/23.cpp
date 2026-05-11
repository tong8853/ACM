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
    cin >> s;
    map<char, int> mp;
    rep(i, 0, s.size() - 1){
        mp[s[i]]++;
    }
    int a[5];
    a[1] = mp['G'] + mp['g'];
    a[2] = mp['P'] + mp['p'];
    a[3] = mp['L'] + mp['l'];
    a[4] = mp['T'] + mp['t'];
    int lun = *max_element(a+1, a+5);
    rep(i, 1, lun){
        if((a[1]--) > 0) cout << 'G';
        if((a[2]--) > 0) cout << 'P';
        if((a[3]--) > 0) cout << 'L';
        if((a[4]--) > 0) cout << 'T';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)solve();
}