// ans.cpp 5 Nov 16, 11:41:48 50 0.99 Judging completed in 5.193s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,d,f;
    cin>>a>>b;
    vector<int> e;
    for(long long int c=0;c<b;c=c+1){
        cin>>d;
        e.push_back(d);
    }
    while(1==1){
        b=0;
        for(long long int c=0;c<e.size()-1;c=c+1){
            if(e[c]>e[c+1]){
                f=e[c];
                e[c]=e[c+1];
                e[c+1]=f;
                b=1;
            }
        }
        if(b==0) break;
    }
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