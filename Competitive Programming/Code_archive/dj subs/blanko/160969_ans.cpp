// ans.cpp 10 Nov 16, 20:56:56 0 1 Judging completed in 5.439s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans=0;
    pair<int,int> min;
    cin>>a>>b;
    char d[a];
    cin>>d;
    min.second=0;
    for(int e=0;e<(a-b);e++){
        if(min.second<a)min.first=d[min.second+1]-'0';
        else min.first=d[min.second-1]-'0';
        if(min.first==0)min.first=d[min.second+2]-'0';
        for(int c=min.second;c<a-(a-b)+e+1;c++){
            if(c>=a) break;
            if((min.first>d[c]-'0')&&((e!=0)||(d[c]-'0'!=0))){
                min.first=d[c]-'0';
                min.second=c+1;
            }
        }
        ans=ans*10+min.first;
    }
    cout<<ans;
    return 0;
}