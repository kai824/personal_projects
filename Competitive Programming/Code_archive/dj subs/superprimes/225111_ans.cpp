// ans.cpp 20 Oct 17, 22:02:48 100 1.06 Judging completed in 6.573s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
char sieve[30000005];
int main(){
    int n,count=0,a=-1,u;
    cin>>n;
    for(int x=2;x<=30000000;x++){
        sieve[x]='x';
    }
    for(int x=2;x<=30000000;x++){
        if(sieve[x]=='x'){
            count++;
            if(a==-1){
                if(count==n){
                    a=x;
                }
            }else{
                if(count==a){
                    cout<<x;
                    break;
                }
            }
            
            u=2*x;
            while(u<30000005){
            	sieve[u]='n';
            	u+=x;
            }
        }
    }
    return 0;
}