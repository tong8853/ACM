#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define PII pair<ll, ll>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T>
inline void read(T &a, int l, int r){
    for(int i = l; i <= r; i++) cin >> a[i];
}

const int N = 2e5+5, M = 1e6+5;
const ll INF = 1e15, p = 1e9+7;       // 注意判断 INF 具体的可能值

inline void solve(){
    int n;cin >> n;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    rep(i, 1, n){
        ll c, w;
        cin >> c >> w;
        pq.push({w, c});
    }
    ll sum = 0;
    while(!pq.empty()){
        PII cur = pq.top();
        pq.pop();
        ll w1 = cur.ff;
        ll c1 = cur.ss;

        while(!pq.empty() && pq.top().ff == w1){
            c1 += pq.top().ss;
            pq.pop();
        }

        if(pq.empty() && c1 == 1) break;
        if(c1 >= 2){
            //先合成里面的
            ll m = c1 / 2;
            ll nw = w1 * 2;

            sum = (sum + (m % p) * (nw % p)) % p;
            pq.push({nw, m});

            if(c1 % 2 == 1){//又剩
                pq.push({w1, 1});
            }
        }else{
            PII ncur = pq.top();
            pq.pop();

            ll w2 = ncur.ff;
            ll c2 = ncur.ss;

            ll nw = w1 + w2;
            sum = (sum + nw % p) % p;

            pq.push({nw, 1});
            if(c2 > 1){
                pq.push({w2, c2 - 1});
            }
        }
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}