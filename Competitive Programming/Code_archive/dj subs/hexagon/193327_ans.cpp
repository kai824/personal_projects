// ans.cpp 18 Feb 17, 23:37:52 100 0 Judging completed in 6.449s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a;
    b=a;
    for(int x=a-1;x>=0;x--){
        for(int y=0;y<x;y++){cout<<' ';}
        for(int y=0;y<b;y++){cout<<'x';}
        cout<<endl;
        b+=2;
    }b-=4;
    for(int x=1;x<a;x++){
    	for(int y=0;y<x;y++){cout<<' ';}
    	for(int y=0;y<b;y++){cout<<'x';}
    	b-=2;
    	cout<<endl;
    }
    return 0;
}