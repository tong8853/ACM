#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    int k;

    while (cin >> k && k)
    {
        vector<int> row(k);

        int n = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> row[i];
            n += row[i];
        }

        // 30以内所有质数
        vector<int> prime = {2,3,5,7,11,13,17,19,23,29};

        map<int,int> cnt;

        // 分解 n!
        for (int i = 2; i <= n; i++)
        {
            int x = i;
            for (int p : prime)
            {
                while (x % p == 0)
                {
                    cnt[p]++;
                    x /= p;
                }
            }
        }

        // 分解所有 hook
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < row[i]; j++)
            {
                int right = row[i] - j - 1;

                int down = 0;
                for (int t = i + 1; t < k; t++)
                    if (row[t] > j)
                        down++;

                int hook = 1 + right + down;

                int x = hook;
                for (int p : prime)
                {
                    while (x % p == 0)
                    {
                        cnt[p]--;
                        x /= p;
                    }
                }
            }
        }

        LL ans = 1;

        for (int p : prime)
        {
            while (cnt[p]--)
                ans *= p;
        }

        cout << ans << endl;
    }

    return 0;
}