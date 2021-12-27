// ans.cpp 23 Nov 20, 14:42:42 44.01 0.04 Judging completed in 3.723s on AWS Oregon.
#import<ios>
int n,i,j;
int main(){for(scanf("%d",&n);i<n;j=(j<0?++i:j))
printf("%d",i+1-j),printf(j--?" ":"\n");
}