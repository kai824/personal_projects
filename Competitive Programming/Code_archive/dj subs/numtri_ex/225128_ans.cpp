// ans.cpp 20 Oct 17, 22:15:46 0 0.03 Judging completed in 3.438s on AWS Oregon.
#import<ios>
int x,y,n;main(){for(scanf("%d",&n);x<n;x++)for(y=1;y<=x+1;y++)printf(((y+1)<=x?"%d ":"%d\n"),y);}