// ans.cpp 18 Oct 17, 21:06:22 50 16.99 Judging completed in 23.107s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    int c,maxi=0;
    cin>>a>>b;
    if(a.length()>b.length())swap(a,b);
    for(int x=0;x<a.length();x++){
        
        c=0;
        
        for(int y=0;(y+x)<a.length();y++){
            if(b.find(a.substr(x,y))==string::npos){
                break;
            }
            c++;
        }
        maxi=max(c-1,maxi);
    }
    cout<<maxi;
    return 0;
}