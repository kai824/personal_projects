// ans.cpp 17 Oct 17, 22:22:39 0 0.35 Judging completed in 5.938s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,ft[200005],a,c;
vector<int> arr[200005];
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
bool cmp(pair<int,int> a,pair<int,int> b){
    return(a.second<b.second);
}
int main(){
    cin>>n;
    pair<int,int> data[n],compress[n];
    for(int x=0;x<n;x++){
        cin>>data[x].first;
        compress[x].first=data[x].first;
        compress[x].second=x;
    }
    
    sort(compress,compress+n);//compressing values
    for(int x=0;x<n;x++){
        if(x==0||compress[x].first!=compress[x-1].first)a++;
        data[compress[x].second].first=a;
    }
    
    for(int x=0;x<n;x++){
        cin>>data[x].second;
        compress[x].first=data[x].second;
        compress[x].second=x;
    }
    sort(compress,compress+n);
    for(int x=0;x<n;x++){
    	if(x==0||compress[x].first!=compress[x-1].first)a++;
        data[compress[x].second].second=a;
    }
    a=0;//now used as ans...
    sort(data,data+n,cmp);
    for(int x=0;x<n;x++){
        update(data[x].first,1);
        a+=query(data[x].first-1);
        //a-=arr[data[x].second];
        for(int y=0;y<arr[data[x].second].size();y++){
        	if(arr[data[x].second][y]<data[x].first)a--;
        }
        
        //arr[data[x].second].push_back(data[x].first);
        
        //cout<<data[x].first<<' '<<data[x].second<<'\n';
    }
    cout<<a;
    return 0;
}