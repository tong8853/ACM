#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define rep2(i, a, b) for (int (i) = (a); (i) >= (b); --i)
using PII = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 5;
ll n, m, a[N], tree[N * 4], mark[N * 4]; // 经验表明开四倍空间不会越界

inline void push_down(ll p, ll len){
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * ((len + 1) / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;
}

void update(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n){
    if (cl > r || cr < l) return;
    else if (cl >= l && cr <= r){
        tree[p] += (cr - cl + 1) * d;
        if (cr > cl)
            mark[p] += d;
    }else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        update(l, r, d, p * 2, cl, mid);
        update(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n){
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[p];
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr);
    }
}

void build(ll l = 1, ll r = n, ll p = 1){
    if(l == r){
        tree[p] = a[l];
    }else{
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

void solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build();
    rep(i, 0, m - 1){
        ll op,l,r;
        cin >> op >> l >> r;
        if(op == 1){
            ll d;cin >> d;
            update(l, r, d);
        }else cout << query(l, r) << endl;
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