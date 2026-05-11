#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=(a); i <=(b); i++)
#define QAQ(x) cout<<#x<<": "<<(x)<<endl, exit(0);
#define endl '\n'
#define int long long
using namespace std;	
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, M = 1e6+5;
const ll INF = 1e15, mod = 998244353;	

int a[N];


void solve(){
    string s; cin>>s;
    int c2=0, c3=0, sum = 0;
    for(auto c : s){
        if(c == '2'){
            ++c2;
        }else if(c == '3'){
            ++c3;
        }
        sum += c-'0';
    }
    auto check = [&](){
        if(sum % 9 == 0) return true;
        int d = 9 - sum%9;
        REP(i, 0, min(9ll, c2)){            // 当 i >= 9 时, 在模意义下重复了
            REP(j, 0, min(9ll, c3)){
                if((i*2 + j*6)%9 == d){
                    return true;
                }
            }
        }
        return false;
    };

    cout<<(check() ?"YES" :"NO")<<endl;
}


signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}