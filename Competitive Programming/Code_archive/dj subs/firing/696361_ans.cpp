// ans.cpp 8 Feb 20, 12:31:10 32 1.92 Judging completed in 5.76s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
int nex[10005];
typedef pair<int,pair<int,int> >  piii;

bool fired[10005];
pair<int,int> tmp;
set<piii>::iterator its[10005];
set<piii> ss;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b,ff=0,q;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>nex[x];
    }
    for(int x=1;x<=n;x++){
        cin>>a;
        ss.insert(make_pair(a,make_pair(x,nex[x]) ) );
				its[x]=ss.find(make_pair(a,make_pair(x,nex[x]) ) );
    }
    for(auto it=ss.begin();it!=ss.end();it++){
        if(fired[it->second.first]==false){
            fired[it->second.second]=true;
            ff++;
        }
    }
    cin>>q;
    cout<<n-ff<<'\n';
    for(int x=0;x<q;x++){
        cin>>a>>b;//change the time of a firing to b...
        ff=0;
        tmp=its[a]->second;
				ss.erase(its[a]);
        ss.insert(make_pair(b,tmp));
				its[a]=ss.find(make_pair(b,tmp));
				for(int x=1;x<=n;x++){
					fired[x]=false;
				}
        for(auto it=ss.begin();it!=ss.end();it++){
            if(fired[it->second.first]==false){
                fired[it->second.second]=true;
                ff++;
            }
        }
        cout<<n-ff<<'\n';
    }
    return 0;
}