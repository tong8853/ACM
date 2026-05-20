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
    vll seg(n << 2), tag(n << 2);
    rep(i, 1, n) cin >> a[i];
    auto pushup = [&](int k){
        seg[k] = seg[k * 2] + seg[k * 2 + 1];
    };

    auto pushdown = [&](ll k, ll l, ll r){ //为了清除当前laze标记，先需要对当前lazy标志对应的两个子区间完成修改，而后将当前的标记传递到两个子区间
        if(tag[k]){
            ll mid = (l + r) / 2;
            seg[k * 2] += tag[k] * (mid - l + 1);
            seg[k*2+1] += tag[k] + (r - (mid + 1) + 1);

            tag[k * 2] += tag[k];
            tag[k*2+1] += tag[k];
            tag[k] = 0;
        }
    }
    auto build = [&](auto self, ll k, ll l, ll r)->void{
        if(l == r){
            seg[k] = a[l];
            return;
        }

        ll mid = (l + r) / 2;
        self(self, k * 2, l, mid);
        self(self, k*2+1, mid+1, r);

        pushup(k);
    };

    auto query = [&](auto self, ll k, ll l, ll r, ll L, ll R, ll val)->ll{
        if(L <= l && r <= R){
            return seg[k];
        }
        pushdown(k, l, r);
        ll mid = (l + r) / 2;
        ll ans = 0;
        if(L <= mid) ans += self(self, k * 2, l, mid, L, R);
        if(mid + 1 <= R) ans += self(self, k * 2 + 1, mid+1, r, L, R);
        return ans; 
    }

    auto update = [&](auto slef, ll k, ll l, ll r, ll L, ll R, ll val)->void{
        if(L <= l && r <= R){
            tag[k] += val;
            seg[k] += (r - l + 1) * val;
            return;
        }

        pushdown(k, l, r);
        ll mid = (l + r) / 2;
        if(L <= mid) update(k * 2, l, mid, L, R, val);
        if(mid + 1 <= R) update(k * 2, mid + 1, r, L, R, val);
        pushup(k);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //ci
    n >> T;
    while(T--) solve();
    return 0;
}