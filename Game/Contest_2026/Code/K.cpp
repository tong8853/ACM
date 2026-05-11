#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    while(b)
    {
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}

int main()
{
    unsigned int r, n;
    cin>>r>>n;

    cout<<"0/1 "<<r<<"/1\n";

    int cnt=1;
    const double k = sqrt(2)+1;
    for(int i=1;cnt<n;i++)
    {
        const int b = i*k;
        for(int j=i+1;j<=b&&cnt<n;j++)
        {
            if(gcd(i, j) != 1)
                continue;
            
            const int p1 = (j*j - i*i)*r;
            const int p2 = i*j*2*r;
            const int q = i*i + j*j;

            const int g1 = gcd(p1, q);
            const int g2 = gcd(p2, q);

            cout<<(p1/g1)<<'/'<<(q/g1)<<' '<<(p2/g2)<<'/'<<(q/g2)<<'\n';

            cnt++;
        }
    }

    return 0;
}
