// ans.cpp 23 Nov 20, 14:42:17 0 0 Judging completed in 8.691s on AWS Oregon.
#import<ios>
int n,i,j;
int main(){for(scanf("%d",&n);i<n;j=(j?++i:j-1))
printf("%d",i+1-j),printf(j?" ":"\n");
}