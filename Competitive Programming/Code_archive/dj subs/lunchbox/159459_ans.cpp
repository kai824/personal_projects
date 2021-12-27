// ans.cpp 5 Nov 16, 14:19:27 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,d,f;
    cin>>a>>b;
    vector<int> e;
    for(int c=0;c<b;c=c+1){
        cin>>d;
        e.push_back(d);
    }
    sort(e.begin(),e.end())
    b=0;
    f=0;
    for(int c=0;c<e.size();c=c+1){
        if(b+e[c]<=a){
            b=b+e[c];
            f=f+1;
        }
    }
    cout<<f;
    return 0;
}