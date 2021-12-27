// ans.cpp 9 Aug 17, 13:49:31 100 0 Judging completed in 10.399s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,arr[25],ans;
    bool stuff[20005];
    while(cin>>n){
        if(n==0)break;
        memset(stuff,false,sizeof(stuff));
        for(int x=0;x<n;x++){
            cin>>arr[x];
            stuff[arr[x]]=true;
        }
        for(int x=0;x<n;x++){
            for(int y=x+1;y<n;y++){
                stuff[arr[x]+arr[y]]=true;
            }
        }
        ans=0;
        for(int x=0;x<20005;x++){
            if(stuff[x])ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}