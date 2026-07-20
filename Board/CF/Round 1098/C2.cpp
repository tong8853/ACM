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
    ll a, n;
    cin >> a >> n;
    vi d(n);
    rep(i, 0, n - 1) cin >> d[i];
    string s = to_string(a);
    int len = s.size();

    if(n == 1 && d[0] == 0){
        cout << a << endl;
        return;
    }

    int maxx = d.back();
    int minx = d.front();
    int m_nz = -1;
    for(int x : d){
        if(x > 0){
            m_nz = x;
            break;
        }
    }

    vector<ll> cands; //candidates
    
    if(len > 1){
        string s1 = "";
        rep(i, 1, len - 1) s1 += to_string(maxx);
        cands.push_back(stoll(s1));
    }
    
    
    string s1 = "";
    s1 += to_string(m_nz);
    rep(i, 1, len) s1 += to_string(minx);
    cands.push_back(stoll(s1));
    
    
    string pre = "";
    rep(i, 0, len){
        if(i == len){
            cands.push_back(stoll(s));
            break;
        }

        int best_less = -1;
        for(int x : d){
            if(x < s[i] - '0')  best_less = max(best_less, x);
        }

        if(best_less != -1){
            string s1 = pre;
            s1 += to_string(best_less);
            rep(j, i + 1, len - 1) s1 += to_string(maxx);
            cands.push_back(stoll(s1));
        }

        int best_greater = 10;
        for(int x : d){
            if(x > s[i] - '0') best_greater = min(best_greater, x);
        }

        if(best_greater != 10){
            string s1 = pre;
            s1 += to_string(best_greater);
            rep(j, i + 1, len - 1) s1 += to_string(minx);
            cands.push_back((stoll(s1)));
        }

        bool ok = 0;
        for(int x : d){
            if(x == s[i] - '0'){
                ok = 1;
                break;
            }
        }
        if(!ok) break;

        pre += s[i];
    }


    ll ans = 2e18;
    for(auto x : cands){
        ans = min(ans, llabs(a - x));
    }
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