// ans.cpp 19 Sep 17, 20:28:14 91 0 Judging completed in 38.058s on AWS Oregon.
#import<ios>
float x=4;
int n,i=80;
main(){scanf("%d",&n);while(i>n&i>39){x-=.4;i>70?i-=10:i-=5;}printf("%.1f",x);}