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
    ll l, r;
    cin >> l >> r;
    ll prel, prer;
    l--;
    if(l % 4 == 1) prel = 1;
    else if(l % 4 == 2) prel = l + 1;
    else if(l % 4 == 3) prel = 0;
    else if(l % 4 == 0) prel = l;

    if(r % 4 == 1) prer = 1;
    else if(r % 4 == 2) prer = r + 1;
    else if(r % 4 == 3) prer = 0;
    else if(r % 4 == 0) prer = r;
    ll ans =prel ^ prer;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}