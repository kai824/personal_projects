// ans.cpp 12 Nov 18, 13:09:28 100 0.12 Judging completed in 3.679s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string s;
    int i,n,x,k,curr=-1,i1=0,i2=0;
    char a;
    deque<pair<char,int> >dq;
    
    cin>>n>>k;
    int v[n];
    k=n-k;
    for (i=0;i<n-k;i++){
    	cin>>a;
    	if (a=='0'){
    		v[i2]=i;
    		i2++;
    	}
    	else {
    		while (!dq.empty()&&dq.back().first>a){
    			dq.pop_back();
    		}
    		dq.push_back({a,i});
    		
    	}
    }
    for (i=n-k;i<n;i++){
    	cin>>a;
    	if (a=='0'){
    		v[i2]=i;
    		i2++;
    	}
    	else {
    		while (!dq.empty()&&dq.back().first>a){
    			dq.pop_back();
    		}
    		dq.push_back({a,i});
    	}
    	if (i>n-k||k==1) {
    		while (i1<i2&&v[i1]<curr){
    			i1++;
    		}
    		while (!dq.empty()&&dq.front().second<curr){
    			dq.pop_front();
    		}
    	}
    	if (k==1&&i1!=i2){
    		printf("0");
    		curr=v[i1];
    		i1++;
    	}
    	else if ((i1==i2||i==n-k)){
    		printf("%c",dq.front().first);
    		curr=dq.front().second;
    		dq.pop_front();
    	}
    	else {
    		printf("0");
    		curr=v[i1];
    		i1++;
    	}
    	
    }
    
}