// ans.cpp 31 Mar 19, 17:04:43 0 0.49 Judging completed in 4.664s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int walls[300005];
map<int,int> ps;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int l,r,a,l_end,r_end,cur=0,ans=0;
    cin>>l>>r;
    ps[1]=0;
	ps[l+1]=0;
    for(int x=0;x<r;x++){
        cin>>a;
        l_end=0;
        for(int y=0;y<a;y++){
            cin>>walls[y];
            l_end+=walls[y];
        }
        r_end=l+1;
        for(int y=0;y<a;y++){//slide right to left...
            r_end-=walls[y];
            if(r_end<=l_end){
                //update r_end to l_end inclusive
                if(ps.find(r_end)==ps.end())ps[r_end]=0;
                ps[r_end]+=1;
                if(ps.find(l_end+1)==ps.end())ps[l_end+1]=0;
                ps[l_end+1]-=1;
				//cout<<r_end<<' '<<l_end<<' '<<x<<'\n';
            }
            l_end-=walls[y];
        }
    }return 0;
    map<int,int>::iterator it=ps.begin();
    while(it!=ps.end()){
        cur+=it->second;
        if(cur!=0){
            a=it->first;
            it++;
			if(it==ps.end())break;
            ans+=it->first-min(a,l);
			//cout<<it->first<<'\n';
        }else it++;
    }
    cout<<ans;
    return 0;
}