// ans.cpp 23 Sep 17, 22:34:10 60 0.99 Judging completed in 4.787s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i=0,p,q,sum=0,tc,i1;
    int arr[1000099]={0};
    for (i=2;i<=1000099;i++){
    	if (arr[i]==0){
    		arr[i]=1;
    		for (i1=i+i;i1<=1000099;i1+=i){
    			arr[i1]=-1;
    		}
    	}
    }
    
    cin>>tc;
    for (i1=0;i1<tc;i1++){
    cin>>p>>q;
    for (i=p;i<=q;i++){
      if (arr[i]==1){
        sum++;
      }
    }
    cout<<sum<<endl;
    sum=0;
    }
}