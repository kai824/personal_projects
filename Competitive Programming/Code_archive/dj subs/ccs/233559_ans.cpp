// ans.cpp 28 Oct 17, 13:01:39 21 1 Judging completed in 5.294s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q,i,x,y,i1,sum=0;
    vector <int> s,output;
    
    string a;
    cin>>n>>q;
    for (i=0;i<q;i++){
    	sum=0;
    	cin>>a;
    	if (a=="TRANSMIT"){
    		
    		cin>>x>>y;
    		for (i1=0;i1<s.size();i1++){
    			sum=0;
    			if ((s[i1]>=x)&&(s[i1]<=y)){
    				
    			output.push_back(0);
    			sum++;
    			break;
    			}
    			
    			
    		}
    	
    		if (sum==0){
    		output.push_back(1);	
    		}
    	}
    	else if (a=="SLEEP"){
    		cin>>x;
    		s.push_back(x);
    	}
    	else if (a=="WAKE"){
    		cin>>x;
    		for (i1=0;i1<s.size();i1++){
    		
    			if (s[i1]==x){
    				s.erase(s.begin()+i1);
    				
    				break;
    			}
    		
    		}
    	}
    }
    for (i=0;i<output.size();i++){
    	
   	if (output[i]==1){
    		cout<<"YES"<<endl;
    	}
    	else cout<<"NO"<<endl;
    } 
}