// ans.cpp 18 Oct 17, 20:59:43 40 0.27 Judging completed in 3.247s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    int lo,hi,mid,maxi=0;
    cin>>a>>b;
    if(a.length()>b.length())swap(a,b);
    for(int x=0;x<a.length();x++){
        lo=0;hi=a.length()-x;
        while(lo<hi){
            mid=(lo+hi)-((lo+hi)/2);
            if(b.find(a.substr(x,mid))==string::npos){//not found
                hi=lo-1;
            }else{
                lo=mid;
            }
        }
        maxi=max(lo,maxi);
    }
    cout<<maxi;
    return 0;
}