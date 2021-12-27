// ans.cpp 23 Nov 20, 14:38:16 59.87 0.04 Judging completed in 3.813s on AWS Oregon.
#import<ios>
int n,i,j;
main(){for(scanf("%d",&n);i<n;j=(j<0?++i:j))printf("%d",i+1-j),printf(j--?" ":"\n");}