// ans.cpp 24 Feb 17, 12:08:44 30 1 Judging completed in 5.682s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b,ans="";
    int c;
    cin>>a>>b>>c;
    for(int x=0;x<a.length();x+=c){
        for(int y=x;y<x+c;y++){
            ans=ans+" ";
            ans[ans.length()-1]=a[y];
        }
        for(int y=x;y<x+c;y++){
            ans=ans+" ";
            ans[ans.length()-1]=b[y];
        }
    }
    cout<<ans;
    return 0;
}