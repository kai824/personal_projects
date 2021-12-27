// ans.cpp 9 Nov 16, 22:33:20 0 1 Judging completed in 6.362s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans=0;
    pair<int,int> min;
    cin>>a>>b;
    char d[a];
    cin>>d;
    min.first=d[0] - '0';
    min.second=0;
    for(int e=0;e<=(a-b);e++){
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