// ans.cpp 9 Nov 16, 22:32:26 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans=0;
    pair<int> min;
    cin>>a>>b;
    char d[a];
    cin>>d;
    min.first=d[0] - '0';
    min.second=0;
    for(int e=0;e<=(a-b);c++){
        for(int c=min.second;c<=(a-b);c++){
            if(min.first>d[c]-'0'){
                min.first=d[c]-'0';
                min.second=c;
            }
        }
        ans=ans*10+min.first;
    }
    cout<<ans;
    return 0;
}