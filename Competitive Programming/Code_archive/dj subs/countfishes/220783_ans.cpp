// ans.cpp 23 Sep 17, 22:40:20 100 0.25 Judging completed in 12.147s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i=0,p,q,sum=0,tc,i1;
    int arr[1000099]={0},ps[1000099]={0};
    for (i=2;i<=1000099;i++){
    	if (arr[i]==0){
    		arr[i]=1;
    		for (i1=i+i;i1<=1000099;i1+=i){
    			arr[i1]=-1;
    		}
    	}
    	ps[i]=ps[i-1];
    	if(arr[i]==1)ps[i]++;
    }
    
    cin>>tc;
    for (i1=0;i1<tc;i1++){
    cin>>p>>q;
    cout<<ps[q]-ps[p-1]<<endl;
    sum=0;
    }
}