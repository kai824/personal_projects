// ans.cpp 13 Dec 16, 19:06:16 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int h,w,ans=0;
    cin>>h>>w;
    string a;
    for(int x=0;x<h;x++){
        cin>>a;
        for(int y=0;y<w;y++){
            if(a[y]=='*')ans++
        }
    }
    cout<<ans;
    return 0;
}