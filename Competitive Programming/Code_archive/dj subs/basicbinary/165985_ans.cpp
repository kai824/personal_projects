// ans.cpp 28 Nov 16, 16:28:59 100 0 Judging completed in 7.006s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int ipow(int b){//raises 2 to the power of b
    int ans=1;
    for(int a=0;a<b;a++){
        ans=ans*2;
    }
    return ans;
}
int main() {
    string bin_num;
    int ans=0,b=0;
    cin>>bin_num;
    for(int a=bin_num.length()-1;a>=0;a--){
        if(bin_num[a]=='1')ans=ans+ipow(b);
        b++;
    }
    cout<<ans;
    return 0;
}