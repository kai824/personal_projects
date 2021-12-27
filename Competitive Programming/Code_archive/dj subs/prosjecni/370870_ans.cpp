// ans.cpp 18 Jun 18, 11:03:57 100 0 Judging completed in 2.261s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,current;
    cin>>n;
    if((n%2)==0){
        if(n==2)cout<<"-1\n";
        else{
			current=0;
            for(int x=1;x<=n;x++){
				if(x==n){
					current=((3*n/2)-1)*(3*n/2);
				}
				for(int y=1;y<=n;y++){
					if(y==n){
						current+=(3*n/2)-n+1;
					}else{
						current+=1;
					}
					cout<<current;
					if(y<n)cout<<' ';
				}
				cout<<'\n';
			}
        }
    }else{
        for(int x=1;x<=n*n;x++){
            cout<<x;
            if((x%n)==0){
                cout<<'\n';
            }else cout<<' ';
        }
    }
    return 0;
}