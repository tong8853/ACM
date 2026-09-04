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
    multiset<int> lf;
    multiset<int> rt;
    
    auto Insert = [&](int x){
        if(lf.empty() || x <= *lf.rbegin()){
            lf.insert(x);
            if(lf.size() > rt.size() + 1){
                rt.insert(*lf.rbegin());
                lf.erase(prev(lf.end()));
            }
        }else{
            rt.insert(x);
            if(lf.size() < rt.size()){
                lf.insert(*rt.begin());
                rt.erase(rt.begin());
            }
        }
    };
    
    auto Erase = [&](int x){
        if(!lf.empty() && x <= *lf.rbegin()){
            lf.erase(lf.find(x));
            if(lf.size() < rt.size()){
                lf.insert(*rt.begin());
                rt.erase(rt.begin());
            }
        }else{
            rt.erase(rt.find(x));
            if(lf.size() > rt.size() + 1){
                rt.insert(*lf.rbegin());
                lf.erase(prev(lf.end()));
            }
        }
    };
    
    auto Mid = [&]() -> int{
        if(lf.empty()){
            return 0;
        }
        if(lf.size() > rt.size()){
            return *lf.rbegin();
        }
        int res = *lf.rbegin() + *rt.begin();
        if(res & 1){
            return -1;
        }
        return res >> 1;
    };
    
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}