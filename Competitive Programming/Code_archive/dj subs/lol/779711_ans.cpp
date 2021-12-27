// ans.cpp 9 Nov 20, 14:47:55 100 0.03 Judging completed in 3.467s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,ans=0;
    string b;
    cin>>a>>b;
    int s[b.length()];//storing the number of Ls before an O.
    a=0;
    for(int x=0;x<b.length();x++){
        if(b[x]=='L')a++;
        else{
            s[x]=a;
        }
    }
    a=0;
    for(int x=0;x<b.length();x++){
        if(b[x]=='O')a+=s[x];
        else{
            ans+=a;
        }
    }
    cout<<ans;
    return 0;
}