#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double R = 1;
int t,r1,r2,n;
double r0,d,a,b,r,s;
double ans;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r1,&r2,&n);
        if(r2<r1)swap(r1,r2);
        d=R*(r1+r2)/r2/r1/4;
        r0=d-R/2/r1;
        r=r2-r1;
        ans=pi*r*r;
        for(int i=1;i<=n/2;++i){
            a=sqrt(d*d+i*r0*i*r0*4)-r0,b=a+r0*2;
            r=(R/a-R/b)/2;
            s=pi*r*r;
            ans+=s;
            if(i*2<n)ans+=s;
            if(s*(n-i*2)<1e-6){
                break;
            }
        }
        printf("%.5f\n",ans);
    }
    return 0;
}