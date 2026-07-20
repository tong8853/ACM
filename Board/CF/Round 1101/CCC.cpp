```
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll s, t;

ll eval(string &S, int m)
{
    ll T = 0, ans = 0;

    for(char c: S)
    {
        if(c == 'I')
        {
            if(T < t)
            {
                T++;
                ans++;
            }
        }
        else if(c == 'E')
        {
            if(ans < T * s) ans++;
        }
        else
        {
            if(m-->0)
            {
                if(T < t)
                {
                    T++;
                    ans++;
                }
            }
            else
            {
                if(ans < T * s) ans++;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 1;
	cin >> T;
    while(T-->0)
    {
        int n;
        cin >> n >> t >> s;

        string S;
        cin >> S;

        int l = 0, r = 0;
        for(char c: S) if(c == 'A') r++;

        while(l < r)
        {
            int m = (l + r) / 2;

            int x = eval(S, m), y = eval(S, m + 1);

            if(x < y) l = m + 1;
            else r = m;
        }

        cout << eval(S, l) << "\n";
    }
}```