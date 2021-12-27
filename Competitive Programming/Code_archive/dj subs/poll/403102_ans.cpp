// ans.cpp 4 Nov 18, 22:50:06 100 0.07 Judging completed in 5.16s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int j[n],g[n],jj=0,gg=0,a,b,c=0;
    for(int x=0;x<n;x++){
        cin>>j[x];
    }
    for(int x=0;x<n;x++){
        cin>>g[x];
    }
    for(int x=0;x<n;x++){
        if(j[x]>g[x])jj++;
        else gg++;
    }
    if(jj>gg){
		cout<<0;return 0;
	}
    for(int x=0;x+1<n;){
        a=0;
        if(g[x]>=j[x])a++;
        if(g[x+1]>=j[x+1])a++;
        b=0;
        if (g[x]+g[x+1]>=j[x]+j[x+1])b++;
        if(a>b){//votes for gx reduced
            x+=2;
            c++;
            gg=gg-a+b;
        }else{
            x++;
        }
        if(jj>gg)break;
    }
    if(jj<=gg)cout<<"-1";
    else cout<<c;
    return 0;
}