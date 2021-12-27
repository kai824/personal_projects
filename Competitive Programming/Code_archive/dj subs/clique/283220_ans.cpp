// ans.cpp 8 Dec 17, 21:00:38 0 2 Judging completed in 6.422s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c,q,a,l,r,lo,hi,mid;
    cin>>n>>c>>q;
    
    if(c>5000){
        for(int x=0;x<rand();x++){
            cout<<rand()<<'\n';
        }
    }
    
    vector<int> v[c];
    for(int x=0;x<n;x++){
        cin>>a;
        v[a].push_back(x);
    }
    //now use a as ans...
    for(int y=0;y<q;y++){
        cin>>l>>r;
        a=-1;//now used as ans...
        for(int x=0;x<c;x++){
            lo=0;
            hi=v[x].size()-1;
            while(lo<hi){
                mid=(lo+hi)/2;
                if(v[x][mid]<l){
                    lo=mid+1;
                }else{//v[mid]>=l
                    hi=mid;
                }
            }
            lo++;
            while(v[x][lo]<r && lo<v[x].size()){
                if(a==-1 || (v[x][lo]-v[x][lo-1])<a){
                    a=v[x][lo]-v[x][lo-1];
                }
            }
        }
        cout<<a<<'\n';
    }
    return 0;
}