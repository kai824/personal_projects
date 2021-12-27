// ans.cpp 20 Aug 17, 17:04:50 0 1.38 Judging completed in 5.769s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct ds{
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> output;
    map<string, ds> mp;
    int a,ans;
    string b;
    short int c,d;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b>>c;
        if(c==1){
            cin>>d;
            mp[b].arr[d]++;
        }else{
            ans=0;
            for(int y=0;y<10;y++){
                ans=max(ans,mp[b].arr[y]);
            }
            output.push_back(ans);
        }
    }
    for(int x=0;x<output.size()-1;x++){
    	cout<<output[x]<<' ';
    }cout<<output.back();
    return 0;
}