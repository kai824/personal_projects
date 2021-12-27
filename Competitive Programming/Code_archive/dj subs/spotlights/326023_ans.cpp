// ans.cpp 14 Feb 18, 08:37:46 16 2.02 Judging completed in 6.83s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,n,current,maxi=INT_MAX,maxx,maxy,prev;
    cin>>r>>c>>n;
    int xx[n],yy[n],hh[n];
    for(int x=0;x<n;x++){
        cin>>yy[x]>>xx[x]>>hh[x];//along c, along r
    }
    
    if(n==2 && c==1){
        if(hh[0]<hh[1]){
            swap(yy[0],yy[1]);
            swap(xx[0],xx[1]);
            swap(hh[0],hh[1]);
        }//ensuring hh[0]>hh[1]
        if(xx[0]<xx[1]){
            prev=hh[0]+abs(yy[0]);
            for(int x=xx[0]+1;x<=xx[1];x++){
                if(max(hh[0]+abs(x-xx[0]) , hh[1]+abs(x-xx[1]))>prev){
                    //previous one was correct...
                    cout<<0<<' '<<x-1<<' '<<prev;
                    return 0;
                }else{
                    prev=max(hh[0]+abs(x-xx[0]) , hh[1]+abs(x-xx[1]));
                }
            }
        }else{
            prev=hh[0]+abs(yy[0]);
            for(int x=xx[0]-1;x>=xx[1];x--){
                if(max(hh[0]+abs(x-xx[0]) , hh[1]+abs(x-xx[1]))>prev){
                    cout<<0<<' '<<x+1<<' '<<prev;
                    return 0;
                }else{
                    prev=max(hh[0]+abs(x-xx[0]) , hh[1]+abs(x-xx[1]));
                }
            }
        }
    }
    
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            current=-1;
            for(int i=0;i<n;i++){
                current=max(current,hh[i]+abs(y-yy[i])+abs(x-xx[i]));
            }
            if(current<maxi){
                maxi=current;
                maxx=x;
                maxy=y;
            }
        }
    }
    cout<<maxy<<' '<<maxx<<' '<<maxi;
    return 0;
}