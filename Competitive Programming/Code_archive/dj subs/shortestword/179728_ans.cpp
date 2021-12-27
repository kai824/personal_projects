// ans.cpp 10 Jan 17, 20:45:53 100 0.26 Judging completed in 3.202s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    pair<string,int>s;
    s.second=INT_MAX;
    string a;
    int b;
    cin>>b;
    for(int x=0;x<b;x++){
        cin>>a;
        if(a.length()<s.second){
            s.second=a.length();
            s.first=a;
        }
    }
    cout<<s.first;
    return 0;
}