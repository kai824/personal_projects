// ans.cpp 12 Nov 18, 23:01:15 0 0.03 Judging completed in 2.155s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,nex=-1,ans;
    cin>>n;
    ans=n;
    list<bool>arr;
    for(int x=0;x<n;x++){
        cin>>a;
        if((a%2)==0){
            arr.push_back(0);
        }else{
            arr.push_back(1);
        }
    }
    for(auto it=arr.begin();it!=arr.end();){
        auto nex_it=it;
        nex_it++;
        if(nex_it==arr.end()){
			it++;
			continue;
		}
        if(*it==*nex_it){
            ans-=2;
            arr.erase(it);
            it=arr.erase(nex_it);
            it--;
        }else it++;
    }
    cout<<ans;
    return 0;
}