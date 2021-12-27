// ans.cpp 20 Oct 17, 22:14:08 0 0.02 Judging completed in 3.366s on AWS Oregon.
#import<ios>
int x,y,n;main(){for(scanf("%d",&n);x<n;x++)for(y=1;y<=x+1;y++)printf((y+1)<=x?"%d ":"%d\n",y);}