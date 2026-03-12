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
    ll ans = 0;
    while(!pq.empty()){
        PII cur = pq.top();
        pq.pop();

        ll w1 = cur.ff;
        ll c1 = cur.ss;

        // 如果这是最后一堆且只有一个，合并完成
        if (pq.empty() && c1 == 1) break;

        if (c1 >= 2) {
            // 1. 内部合并：c1 个重量为 w1 的果子两两合并
            ll pairs = c1 / 2;
            ll new_w = w1 * 2;
            
            // 累加代价：次数 * 产生的单堆重量
            ans = (ans + (pairs % p) * (new_w % p)) % p;
            
            // 产生的新的重量入队
            pq.push({new_w, pairs});
            
            // 剩下的一个（如果有）重新入队
            if (c1 % 2 != 0) {
                pq.push({w1, 1});
            }
        } else {
            // 2. c1 == 1，必须取出队列中下一个最小重量合并
            PII next_cur = pq.top();
            pq.pop();

            ll w2 = next_cur.ff;
            ll c2 = next_cur.ss;

            ll combined_w = w1 + w2;
            ans = (ans + combined_w % p) % p;

            // 合并后产生 1 堆新重量
            pq.push({combined_w, 1});
            
            // w2 剩下的部分重新入队
            if (c2 > 1) {
                pq.push({w2, c2 - 1});
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}