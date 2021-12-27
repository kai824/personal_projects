// ans.cpp 16 Oct 17, 14:04:47 100 0.06 Judging completed in 5.019s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,k,i,i1,arr[100010]={4294967295},x,sum=0,sum1;
    cin>>n>>k;
    for (i=1;i<=n;i++){
    	cin>>x;
    	if (i<=k){
    		arr[i]=x;
    		
    	}
    	else {
    		sum=0;
    		arr[i]=4294967295;
    		for (i1=i-k;i1<i;i1++){
    			sum=max(x,arr[i1]);
    			arr[i]=min(sum,arr[i]);
    		}
    	}
    }
    i=n+1;
    sum=0;
    arr[i]=4294967295;
    for (i1=i-k;i1<i;i1++){
    	arr[i]=min(arr[i1],arr[i]);
    }
    if (k>n)cout<<"0"<<endl;
    else cout<<arr[n+1]<<endl;
    
}