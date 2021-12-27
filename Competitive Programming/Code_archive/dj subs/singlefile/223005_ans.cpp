// ans.cpp 17 Oct 17, 12:29:25 19 1.05 Judging completed in 16.923s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[1000005],n,t,a,ans;
int ft2[1000005];
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
int query2(int p){
    int sum=0;
    for(;p;p-=ls(p))sum+=ft2[p];
    return sum;
}
void update(int p, int v) {
	for(;p<=(n+3);p+=ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
void update2(int p,int v){
    for(;p<=(n+3);p+=ls(p)){
        ft2[p]+=v;
    }
}
int main() {
    cin>>n;
    int arr[n],ans=0;
    vector<int> arr2;
    map<int,int>itmap;
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr2.push_back(arr[x]);
    }
    sort(arr2.begin(),arr2.end());
    arr2.erase(unique(arr2.begin(),arr2.end() ),arr2.end());
    for(int x=0;x<arr2.size();x++){
        itmap[arr2[x]]=x+1;
    }
    for(int x=0;x<n;x++){
        arr[x]=itmap[arr[x]];
    }
    for(int x=0;x<n;x++){
        ans+=query2(n)-query2(arr[x]);
        update2(arr[x],query(n)-query(arr[x]));
        update(arr[x],1);
    }
    cout<<ans;
    return 0;
}