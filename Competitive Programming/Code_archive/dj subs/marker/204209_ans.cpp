// ans.cpp 15 Apr 17, 19:05:53 100 0 Judging completed in 2.901s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s1=0,s2=0,a,b,c;
    char d,e;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a>>d>>b>>e>>c;
        if(d=='+'){
            if(a+b==c)s1++;
        }else{
            if(a-b==c)s1++;
        }
    }
    for(int x=0;x<n;x++){
        cin>>a>>d>>b>>e>>c;
        if(d=='+'){
            if(a+b==c)s2++;
        }else{
            if(a-b==c)s2++;
        }
    }
    cout<<"Spongebob: "<<s1<<"\nPatrick: "<<s2;
    return 0;
}