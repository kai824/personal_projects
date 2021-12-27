// ans.cpp 22 Sep 17, 08:07:26 0 0 Judging completed in 4.423s on AWS Oregon.
#import<ios>
float x=4,n,i=80;
main(){scanf("%d",&n);while(i>n&i>39){x-=.4;i-=i>70?10:5;}printf("%.1f",x);}