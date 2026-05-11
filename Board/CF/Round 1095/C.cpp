#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n - 1) cin >> a[i];
        multiset<int> ms(a.begin(), a.end());
        int l = 0, r = n + 1;
        while(l < r){
            int md = (l + r) / 2;

            bool ok = 1;
            vi removed;

            //检验是否能构造到0~(md-1)的序列，就是看能不能使得mex等于md
            rep2(i, md - 1, 0){
                if(ms.count(i)){
                    removed.push_back(i);
                    ms.erase(ms.find(i));
                }else{
                    int x = *ms.rbegin();
                    if(x >= 2 * i + 1){
                        removed.push_back(x);
                        ms.erase(ms.find(x));
                    }else{
                        ok = 0;
                        break;
                    }
                }
            }

            for(auto &z :removed) ms.insert(z);

            if(ok) l = md + 1;
            else r = md;
        }
        l--;
        cout << l << endl;
    }
    return 0;
}