// ans.cpp 2 Dec 18, 21:33:15 0 0.54 Judging completed in 8.792s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;
bool fits_in(pair<int,int> a,pair<int,int> b){//if a fits in b
		return ((a.first<b.first)&&(a.second<b.second));
}
bool cmp(pair<int,int> a,pair<int,int> b){
		if(a.first==b.first)return(a.second>b.second);
		else return a.first<b.first;
}
int main(){
		ios_base::sync_with_stdio(false);cin.tie(0);
		int n,lo,hi,mid;
		cin>>n;
		pair<int,int> arr[1000000];
		for(int x=0;x<n;x++){
				cin>>arr[x].first;
		}
		for(int x=0;x<n;x++){
				cin>>arr[x].second;
		}
		sort(arr,arr+n,cmp);
		/*for(int x=0;x<n;x++){
			cout<<arr[x].first<<' ';
		}
		cout<<'\n';
		for(int x=0;x<n;x++){
			cout<<arr[x].second<<' ';
		}cout<<'\n';*/
		vector<pair<int,int> > lis;//since need to check strictly decreasing on both
		lis.push_back(arr[0]);
    for(int x=1;x<n;x++){
		//cout<<lis.size()<<'\n';
        if(lis.back().first<arr[x].first && lis.back().second>arr[x].second){
            lis.push_back(arr[x]);
            continue;
        }
        //binary search
        //find smallest number larger or equal to than arr[x]
        //1 2 4...    4
        //|   |
        lo=0;
        hi=lis.size()-1;
        while(lo<hi){
            mid=(lo+hi)/2;
						if(lis[mid].first>=arr[x].first && lis[mid].second<=arr[x].second){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
				if(lis[lo].first>=arr[x].first && lis[lo].second<=arr[x].second)lis[lo]=arr[x];
    }
    cout<<lis.size();
		return 0;
}