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
    ll n;
    cin >> n;
    vll a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vll cha(n + 1);
    rep(i, 1, n){
        cha[i] = a[i] - i;
        if(cha[i] < 0){
            cout << -1 << endl;
            return;
        }
    }
    vll b(n + 1);
    b[n] = cha[n];
    ll op2 = 0;
    rep2(i, n - 1, 1){
        b[i] = min(b[i + 1], cha[i]);
    }
    ll shao = 0,ans=n;
    vll cur(n+1);
    rep(i, 1, n){
        if(b[i]>op2)//可等待数如果超过已操作数就是可操作
        {
            ll temp=min(op2+shao,b[i]);//新的总操作数
            shao=shao-temp+op2;//temp-op2才是这次的真操作数，shao-这次操作数是余下的shao
            op2=temp;
        }
        cur[i]=i+op2;
        shao+=a[i]-cur[i];//a[i]-cur[i]是真实操作2的次数
        ans+=a[i]-cur[i];
       
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
}