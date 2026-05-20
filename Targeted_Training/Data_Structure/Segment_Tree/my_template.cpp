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
    int n, m;
    cin >> n >> m;
    vi a(n + 5);
    vll d(n << 2), b(n << 2);
    rep(i, 1, n) cin >> a[i];
    //递归建树。线段树的核心思想是将一个区间拆分为两个子区间，直到叶子节点代表单个元素.
    auto build = [&](auto self, ll l, ll r, ll p) -> void{
        // l:区间左端点， r:区间右端点， p:根结点
        if(l == r){
            d[p] = a[l];
            return;
        }
        ll m = l + (r - l) / 2; //分界点
        self(self, l, m, p * 2), self(self, m + 1, r, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
    };
    build(build, 1, n, 1);

    //区间加
    auto update_add = [&](auto self, ll l, ll r, ll c, ll s, ll t, ll p) -> void{
        //当当前区间包含在修改区间里面时，不再递归，打上懒标记
        if(l <= s && t <= r){
            d[p] += (t - s + 1) * c;
            b[p] += c; //懒标记，当前节点下的所有节点都需要加c
            return;
        }

        //下传标记
        ll m = s + (t - s) / 2;
        if(b[p]){
            d[p * 2] += b[p] * (m - s + 1);
            d[p*2+1] += b[p] * (t - m);
            b[p * 2] += b[p];
            b[p*2+1] += b[p]; 
        }
        b[p] = 0;

        if(l <= m) self(self, l, r, c, s, m, p * 2);
        if(r > m) self(self, l, r, c, m+1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1]; //计算该节点区间和
    };

    auto getsum = [&](auto self, ll l, ll r, ll s, ll t, ll p)->ll{
        if(l <= s && t <= r) return d[p];
        ll m = s + (t - s) / 2;
        if(b[p]){
            d[p * 2] += b[p] * (m - s + 1);
            d[p*2+1] += b[p] * (t - m);
            b[p * 2] += b[p];
            b[p*2+1] += b[p]; 
        }
        b[p] = 0;
        ll sum = 0;
        if(l <= m) sum += self(self, l, r, s, m, p * 2);
        if(r > m) sum += self(self, l, r, m+1, t, p * 2 + 1);

        return sum;
    };

    
    rep(i, 1, m){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            int k;
            cin >> k;
            update_add(update_add, l, r, k, 1, n, 1);
        }else{
            cout << getsum(getsum, l, r, 1, n, 1) << endl;
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