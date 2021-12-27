// ans.cpp 26 Jun 17, 16:12:50 11 0.09 Judging completed in 9.202s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    bool not_broke;
    cin>>n;
    vector<int> ans,result2;
    int result[(int)(pow(2,n))];
    for(int x=0;x<sizeof(result)/4;x++){
        cin>>result[x];
    }
    for(int x=1;x<sizeof(result)/4;x++){
        not_broke=true;
        for(int y=0;y<result2.size();y++){
            if(result[x]==result2[y]){
                swap(result2[y],result2.back());
                result2.pop_back();
                not_broke=false;
                break;
            }
        }
        if(not_broke){
            for(int y=0;y<ans.size();y++){
                result2.push_back(ans[y]+result[x]);
            }
            ans.push_back(result[x]);
            if(ans.size()==n)break;
        }
    }
    for(int x=0;x<ans.size();x++){
        cout<<ans[x]<<"\n";
    }
    return 0;
}