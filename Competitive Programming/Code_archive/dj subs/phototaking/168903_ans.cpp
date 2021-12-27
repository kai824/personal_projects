// ans.cpp 10 Dec 16, 15:40:47 0 0.99 Judging completed in 6.731s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,ranges=0;//a is the no. of photos, b is the limit, ranges is the answer
    cin>>a>>b;
    int e[a];
    for(int d=0;d<a;d=d+1){
        cin>>c;
        e[d]=c;
    }
    for(int d=0;d<a;d=d+1){
        c=0;
        for(int f=0;f<=(a-d);f=f+1){
            c=c+e[d+f];
            if(c>b) break;
            else ranges=ranges+1;
        }
    }
    cout<<ranges;
    return 0;
}