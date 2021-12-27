// ans.cpp 23 Nov 20, 14:24:16 0 0.03 Judging completed in 3.825s on AWS Oregon.
#import<ios>
int n,i,j;main(){for(scanf("%d",&n);i<n;){printf("%d",i-j--);if(j+1)printf(" ");else puts(""),j=i++;}}