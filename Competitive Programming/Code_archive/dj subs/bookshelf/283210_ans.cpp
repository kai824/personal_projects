// ans.cpp 8 Dec 17, 20:41:30 100 0.38 Judging completed in 4.372s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int start=1000005,end=1000005,t,a;
    map<int,int> mp;//value,it...
    cin>>t;
    for(int x=0;x<t;x++){
    	cin>>a;
    	if(a==1){
    		cin>>a;
    		start--;
    		mp[a]=start;
    	}else if(a==2){
    		cin>>a;
    		mp[a]=end;
    		end++;
    	}else if(a==3){
    		start++;
    	}else if(a==4){
    		end--;
    	}else if(a==5){
    		cin>>a;
    		cout<<mp[a]-start+1<<'\n';
    	}else if(a==6){
    		cin>>a;
    		cout<<end-mp[a]<<'\n';
    	}else{
    		while(true){}
    	}
    }
    return 0;
}