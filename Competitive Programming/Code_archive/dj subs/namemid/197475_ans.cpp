// ans.cpp 8 Mar 17, 12:24:43 100 0 Judging completed in 4.721s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,c=0,d=1;
    string b;
    getline(cin,b);
    cin>>a;
    for(int x=a-1;x>=0;x--){
        for(int y=0;y<x;y++){cout<<' ';}
        for(int y=0;y<d;y++){
            cout<<b[c]<<' ';
            c++;
            if(c>=b.length())c=0;
        }
        d++;
        cout<<endl;
    }
    return 0;
}