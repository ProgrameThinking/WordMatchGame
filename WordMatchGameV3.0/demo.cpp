#include<bits/stdc++.h>
using namespace std;

int main()
{
    int totlanum,a,b;
    cin>>totlanum;
    for(int i=0;i<totlanum;i++)
    {
        cin>>a>>b;
        long long powdeta=8*a-4*a*a+16*b;
        double l1,l2,m1,m2;
        double deta1,deta2;
        deta1=sqrt(powdeta)*(-1.0);
        deta2=sqrt(powdeta);
        l1=(2*a+deta1)/4;
        l2=(2*a+deta2)/4;
        if(fmod(l1,1.0)==0&&l1<=a&&l1>=0)
        {
            puts("YES");
            for(int i=0;i<l1;i++)
                printf("-1 ");
            for(int i=0;i<a-l1-1;i++)
                printf("1 ");
            puts("1");
        }
        else if(fmod(l2,1.0)==0)
        {
            puts("YES");
            puts("YES");
            for(int i=0;i<l2;i++)
                printf("-1 ");
            for(int i=0;i<a-l2-1;i++)
                printf("1 ");
            puts("1");
        }
        else
            puts("NO");
    }
    
    return 0;
}