// ans.cpp 26 Dec 17, 21:51:08 30 1.51 Judging completed in 4.089s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    unsigned int n,k,a,continuous,prev;
    cin>>n>>k;
    for(int y=0;y<n;y++){
        cin>>a;
        if(a<k){
            cout<<"NO\n";
            continue;
        }
        bool broke=false;
        for(int x=2;(x*x<=a&&x<=k);x++){
            if((a%x)==0){
                cout<<"NO\n";
                broke=true;
                break;
            }
        }
        if(broke==true)continue;
        continuous=1;
        prev=a%10;
        a/=10;
        while(a>0){
        	if((a%10)==prev){
        		continuous++;
        		a/=10;
        		if(continuous==4){
        			cout<<"NO\n";
        			broke=true;
        			break;
        		}
        	}else{
        		prev=a%10;
        		a/=10;
        		continuous=1;
        	}
        }
        if(broke==true)continue;
        cout<<"YES\n";
    }
    return 0;
}