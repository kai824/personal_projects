// ans.cpp 23 Nov 20, 14:36:40 54.04 0.04 Judging completed in 9.92s on AWS Oregon.
#import<ios>
int n,i=1,j;main(){for(scanf("%d",&n);i<=n;j=(j<0?i++:j))printf("%d",i-j),printf((j--)?" ":"\n");}