// ans.cpp 17 Oct 17, 20:17:22 0 0 Judging completed in 5.871s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string st(ll a,string b){
	string ans=to_string(a);
	while(ans.length()<b.length()){
		ans="0"+ans;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    ll start=9,n;
    string a;
    cin>>n;
    n--;
    if(n==0){
        cout<<0;
        return 0;
    }
    while(true){
        if(n<=start*2){
        	if(n<start){
        		a=st(n,to_string(start));
            	cout<<a;
	            for(int x=a.length()-1;x>0;x--){
    	            cout<<a[x];
        	    }
        	}else{
        		n-=start;
        		a=st(n,to_string(start));
        		cout<<a;
        		for(int x=a.length()-1;x>=0;x--){
        			cout<<a[x];
        		}
        	}
            break;
        }else{
            n-=(start*2);
            start*=9;
            start+=9;
        }
    }
    return 0;
}