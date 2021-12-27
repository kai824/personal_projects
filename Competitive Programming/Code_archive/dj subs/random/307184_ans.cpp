// ans.cpp 26 Dec 17, 22:05:17 100 0.15 Judging completed in 3.42s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    unsigned int n,k,a,continuous,prev,u;
    bitset<65600>bs;
    vector<int>primes;
    for(int x=2;x<65600;x++){
        if(bs[x]==0){//not marked...
            primes.push_back(x);
            u=x;
            while(u<65600){
                bs[u]=1;//mark it...
                u+=x;
            }
        }
    }
    cin>>n>>k;
    for(int y=0;y<n;y++){
        cin>>a;
        if(a<k){
            cout<<"NO\n";
            continue;
        }
        u=a;
        bool broke=false;
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
        a=u;
        for(int x=0;(primes[x]*primes[x]<=a&&primes[x]<=k&&x<primes.size());x++){
            if((a%primes[x])==0){
                cout<<"NO\n";
                broke=true;
                break;
            }
        }
        if(broke==true)continue;
        cout<<"YES\n";
    }
    return 0;
}