#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void pushup(int k)
{
    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}
void pushdown(int k, int l, int r)
{
    if (tag[k])
    {
        //先计算再传标记
        int mid = (l + r) >> 1;
        tree[k << 1] += tag[k] * (mid - l + 1);
        tree[k << 1 | 1] += tag[k] * (r - (mid + 1) + 1);

        tag[k << 1] += tag[k];
        tag[k << 1 | 1] += tag[k];
        tag[k] = 0; //标记清零
    }
}
void build(int k, int l, int r)
{
    if (l == r)
    {
        tree[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
}
ll query(int k, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return tree[k];
    }
    pushdown(k, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid)
        ans += query(k << 1, l, mid, L, R);
    if (mid + 1 <= R)
        ans += query(k << 1 | 1, mid + 1, r, L, R);
    return ans;
}
void update(int k, int l, int r, int L, int R, ll val)
{
    if (L <= l && r <= R)
    {
        tag[k] += val;
        tree[k] += (r - l + 1) * val; //记得要乘上长度
        return;
    }
    pushdown(k, l, r); //如果是交叉区间，那么需要先传递标记
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(k << 1, l, mid, L, R, val);
    if (mid + 1 <= R)
        update(k << 1 | 1, mid + 1, r, L, R, val);
    pushup(k); //修改的时候，需要向上传标记
}

void solve(){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}