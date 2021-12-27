// ans.cpp 9 Dec 17, 16:11:42 100 0 Judging completed in 3.664s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t,i,i1,n,k,x;
    cin>>t;
    for (i1=0;i1<t;i1++){
    	cin>>n>>k;
    	x=k/n;
    	if (k%n==0)x--;
    	if (n%2==0){
    		k%=n;
    		if (k==0)k=n;
    		if (k%2==1){
    			k++;
    			k/=2;
    		}
    		else {
    			k/=2;
    			k=n-k+1;
    		}
    	}
    	else {
    		n*=2;
    		k%=n;
    		if (k==0)k=n;
    		if (k<=n/2){
    			if (k%2==1){
	    			k++;
	    			k/=2;
	    		}
	    		else {
	    			k/=2;
	    			k=n/2-k+1;
	    		}
    		}
    		else {
    			k-=n/2;
    			if (k%2==0){
	    			k/=2;
	    		}
	    		else {
	    			k++;
	    			k/=2;
	    			k=n/2-k+1;
	    		}
    		}
    	}
    	cout<<k<<" "<<x<<'\n';
    }
    
}