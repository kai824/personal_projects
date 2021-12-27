// ans.cpp 23 Nov 20, 14:27:24 0 0.02 Judging completed in 4.087s on AWS Oregon.
#import<ios>
int n,i=1,j;main(){for(scanf("%d",&n);i<=n;){printf("%d",i-j--);if(j+1)printf(" ");else puts(" "),j=i++;}}