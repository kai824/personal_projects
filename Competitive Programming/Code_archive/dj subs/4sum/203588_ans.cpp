// ans.cpp 5 Apr 17, 20:44:24 100 0.03 Judging completed in 2.736s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1,n2,n3,n4,p1=0,p2=0;
    cin>>n1>>n2>>n3>>n4;
    int a[n1],b[n2],c[n3],d[n4];
    vector<pair<int,pair<int,int> > > arr,arr2;
    for(int x=0;x<n1;x++){
        cin>>a[x];
    }
    for(int x=0;x<n2;x++){
        cin>>b[x];
    }
    for(int x=0;x<n3;x++){
        cin>>c[x];
    }
    for(int x=0;x<n4;x++){
        cin>>d[x];
    }
    for(int x=0;x<n1;x++){
        for(int y=0;y<n2;y++){
            arr.push_back(make_pair(a[x]+b[y],make_pair(a[x],b[y])));
        }
    }
    for(int x=0;x<n3;x++){
        for(int y=0;y<n4;y++){
            arr2.push_back(make_pair((c[x]+d[y])*(-1),make_pair(c[x],d[y])));
        }
    }
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    while(p1<arr.size() && p2<arr2.size()){
        if(arr[p1].first==arr2[p2].first){
            cout<<arr[p1].second.first<<' '<<arr[p1].second.second<<' '<<arr2[p2].second.first<<' '<<arr2[p2].second.second<<'\n';
            break;
        }else if(arr[p1].first<arr2[p2].first){
            p1++;
        }else{
            p2++;
        }
    }
    return 0;
}