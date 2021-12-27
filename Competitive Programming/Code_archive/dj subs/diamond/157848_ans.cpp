// ans.cpp 2 Nov 16, 10:52:35 100 0 Judging completed in 4.754s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        for(int c=0;c<a-(b+1);c=c+1){
            cout<<" ";
        }
        for(int c=0;c<2*b+1;c=c+1){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int b=a-2;b>-1;b=b-1){
    	for(int c=0;c<a-(b+1);c=c+1){
            cout<<" ";
        }
        for(int c=0;c<2*b+1;c=c+1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}