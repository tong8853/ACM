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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    multiset<int> ms(a.begin(), a.end());

    int l = 1, r = n + 1;
    //检查[L, R), 因为小于L的都是合法的，大于等于R的都是不合法的，我们需要找到最大的一个合法的
    while(l < r){
        int mid = (l + r) / 2;
        //需要检测mid作为ans能不能达到
        bool ok = 1;
        vi rm;
        rep2(i, mid - 1, 0){
            if(ms.count(i)){
                rm.push_back(i);
                ms.erase(ms.find(i));
            }else{
                int x = *ms.rbegin();
                if(x >= 2 * i + 1){
                    rm.push_back(x);
                    ms.erase(ms.find(x));
                }else{
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) l = mid + 1;
        else r = mid;

        for(auto &x : rm) ms.insert(x);
    }
    cout << l-1 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}