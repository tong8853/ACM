#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
using namespace std;
using ld=long double;
using ll=long long;
using pll=pair<ll,ll>;
const ld INF=9e18;
const ld two=2;
const int N=1010;
ll x[N],y[N];
map<pll,vector<pll>> m;
bool check(ll dx1,ll dy1,ll dx2,ll dy2)
{
	return dx1*dx2==-dy1*dy2;
}
ll cal(ll ax,ll ay,ll bx,ll by,ll cx,ll cy)
{
	return (bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll ans=-1;
	ll dx1,dy1,dx2,dy2,f1,f2;
	int n,k,i,j;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	for(i=1;i<n;++i)
		for(j=i+1;j<=n;++j)
			m[{x[i]+x[j],y[i]+y[j]}].emplace_back(i,j);
	for(auto &p:m)
	{
		auto &v=p.second;
		k=v.size();
		for(i=0;i<k;++i)
			for(j=i+1;j<k;++j)
			{
				dx1=x[v[i].first]-x[v[i].second];
				dy1=y[v[i].first]-y[v[i].second];
				dx2=x[v[j].first]-x[v[j].second];
				dy2=y[v[j].first]-y[v[j].second];
				f1=cal(x[v[i].first],y[v[i].first],x[v[i].second],y[v[i].second],x[v[j].first],y[v[j].first]);
				f2=cal(x[v[i].first],y[v[i].first],x[v[i].second],y[v[i].second],x[v[j].second],y[v[j].second]);
                if(f1!=0&&f2!=0)
                    ans=max(ans,llabs(f1));
			}
	}
	if(ans==-1)
		cout<<-1;
	else
		cout<<ans<<".0";
	return 0;
}
