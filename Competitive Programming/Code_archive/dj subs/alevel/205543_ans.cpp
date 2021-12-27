// ans.cpp 30 Apr 17, 17:16:43 100 0 Judging completed in 4.985s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    double ans=0,to_add,minh2=30,maxans=0;
    bool h1=false;//true when we're at h2...
    for(int x=0;x<a.length();x++){
        if(a[x]=='/'){
            h1=true;
            continue;
        }
        if(a[x]=='A'){
            to_add=20;
        }else if(a[x]=='B'){
            to_add=17.5;
        }else if(a[x]=='C'){
            to_add=15;
        }else if(a[x]=='D'){
            to_add=12.5;
        }else if(a[x]=='E'){
            to_add=10;
        }else if(a[x]=='S'){
            to_add=5;
        }else if(a[x]=='U'){
            to_add=0;
        }
        if(h1){
            to_add/=2;
            maxans+=10;
        }else{
            minh2=min(minh2,to_add);
            maxans+=20;
        }
        ans+=to_add;
    }
    if(maxans==100){
        ans-=(minh2/2);
    }
    if(floor(ans)==ans){
        cout<<ans;
    }else{
        cout<<floor(ans)+1;
    }
    return 0;
}