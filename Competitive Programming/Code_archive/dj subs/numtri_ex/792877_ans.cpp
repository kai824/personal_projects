// ans.cpp 23 Nov 20, 14:25:00 0 0.03 Judging completed in 13.803s on AWS Oregon.
#import<ios>
int n,i=1,j;main(){for(scanf("%d",&n);i<n;){printf("%d",i-j--);if(j+1)printf(" ");else puts(""),j=i++;}}