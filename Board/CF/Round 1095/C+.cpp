#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
 
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
 
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
 
        multiset<int> ms(a.begin(), a.end());
 
        int l = 0, r = n + 1;
        while(l < r){
            int md = (l + r) / 2;
 
            assert((int)ms.size() == n);
            
            bool is = 1;
            vector<int> removed;
 
            for(int i = md - 1; i >= 0; i--){
                if(ms.count(i)){
                    removed.push_back(i);
                    ms.erase(ms.find(i));
                    continue;
                }
                else{
                    int x = *ms.rbegin();
                    if(x < 2*i + 1){
                        is = 0;
                        break;
                    }
                    removed.push_back(x);
                    ms.erase(ms.find(x));
                }
            }
 
            for(auto& z : removed) ms.insert(z);
 
            if(is) l = md + 1;
            else r = md;
        }
 
        assert(l > 0);
        --l;
 
        cout << l << '\n';
    }
    
}