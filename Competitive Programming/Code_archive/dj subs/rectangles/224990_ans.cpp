// ans.cpp 20 Oct 17, 17:32:35 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    return(a.second<b.second);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,f,x1,x2,y1,y2,lo,hi,mid,cur;
    cin>>n;
    pair<int,int> coords[n],coords2[n];//x, then y...
    for(int x=0;x<n;x++){
        cin>>coords[x].first>>coords[x].second;
        coords2[x]=coords[x];
    }
    qsort(coords,coords+n);
    qsort(coords2,coords2+n,cmp);
    cin>>f;
    for(int x=0;x<f;x++){
        cur=0;
        cin>>x1>>y1>>x2>>y2;
        lo=0;hi=n-1;
        while(lo<hi){//find the smallest that >= x1
            mid=(lo+hi)/2;
            if(coords[mid].first<x1){
                lo=mid+1;
            }else{//coords[mid].first>=x1
                hi=mid;
            }
        }
        while(coords[lo].first==x1){
            if(coords[lo].second>=y1 &&coords[lo].second<=y2){
                cur++;
            }
            lo++;
        }
        
        lo=0;hi=n-1;
        while(lo<hi){//find the smallest that >= x1
            mid=(lo+hi)/2;
            if(coords[mid].first<x2){
                lo=mid+1;
            }else{//coords[mid].first>=x1
                hi=mid;
            }
        }
        while(coords[lo].first==x2){
            if(coords[lo].second>=y1 &&coords[lo].second<=y2){
                cur++;
            }
            lo++;
        }
        
        lo=0;hi=n-1;
        while(lo<hi){//find the smallest that >= x1
            mid=(lo+hi)/2;
            if(coords2[mid].second<y1){
                lo=mid+1;
            }else{//coords[mid].first>=x1
                hi=mid;
            }
        }
        while(coords2[lo].second==y1){
            if(coords2[lo].first>x1 &&coords2[lo].first<x2){
                cur++;
            }
            lo++;
        }
        
        lo=0;hi=n-1;
        while(lo<hi){//find the smallest that >= x1
            mid=(lo+hi)/2;
            if(coords2[mid].second<y2){
                lo=mid+1;
            }else{//coords[mid].first>=x1
                hi=mid;
            }
        }
        while(coords2[lo].second==y2){
            if(coords2[lo].first>x1 &&coords2[lo].first<x2){
                cur++;
            }
            lo++;
        }
        cout<<cur<<'\n';
    }
    return 0;
}