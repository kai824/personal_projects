// ans.cpp 25 Oct 17, 21:12:20 0 0 Judging completed in 4.88s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tc,n,m,a,p1,p2,bb;
    bool b;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        bb=m/n;
        
        if((bb%2)==1 && n%2==1){
        	a=(m-1)%n;
        	p1=n;p2=1;b=0;
        	for(int x=0;x<a;x++){
        		if(b==0)p1--;
        		else p2++;
        		b=!b;
        	}
        	if(b==false){
        		cout<<p1;
        	}else{
        		cout<<p2;
        	}
        	cout<<' '<<bb<<'\n';
        	continue;
        }
        
        a=(m-1)%n;
        p1=1;p2=n;b=0;
        for(int x=0;x<a;x++){
            if(b==0)p1++;
            else p2--;
            b=!b;
        }
        if(b==false){
            cout<<p1;
        }else cout<<p2;
        cout<<' '<<bb<<'\n';
    }
    return 0;
}