// ans.cpp 23 Nov 20, 14:50:28 98 0.03 Judging completed in 3.89s on AWS Oregon.
#import<ios>
int n,i,j;main(){for(scanf("%d",&n);i<n;j=(j--?j:++i))printf(j?"%d ":"%d\n",i+1-j);}