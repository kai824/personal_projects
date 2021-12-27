// ans.cpp 23 Nov 20, 14:25:51 37.74 0.03 Judging completed in 8.838s on AWS Oregon.
#import<ios>
int n,i=1,j;main(){for(scanf("%d",&n);i<=n;){printf("%d",i-j--);if(j+1)printf(" ");else puts(""),j=i++;}}