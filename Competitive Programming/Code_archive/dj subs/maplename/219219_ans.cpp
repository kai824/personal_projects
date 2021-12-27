// ans.cpp 21 Aug 17, 14:20:54 100 0 Judging completed in 6.517s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    if(a=="A"){
        cout<<'o';
        for(int x=0;x<b.length();x++){
            cout<<'-';
        }cout<<"o\n";
        cout<<'|'<<b<<"|\n";
        cout<<'o';
        for(int x=0;x<b.length();x++){
            cout<<'-';
        }cout<<"o";
    }else if(a=="K"){
        cout<<'x';
        for(int x=0;x<b.length();x++){
            cout<<'-';
        }cout<<"x\n";
        cout<<'|'<<b<<"|\n";
        cout<<'x';
        for(int x=0;x<b.length();x++){
            cout<<'-';
        }cout<<"x";
    }else if(a=="H"){
        for(int x=0;x<b.length()+2;x++){
            if(x%2==0)cout<<'o';
            else cout<<'x';
        }
        cout<<"\nx"<<b;
        if((b.length()+1)%2==0)cout<<'x';
        else cout<<'o';
        cout<<'\n';
        for(int x=0;x<b.length()+2;x++){
            if(x%2==0)cout<<'o';
            else cout<<'x';
        }
    }else if(a=="R"){
        cout<<'o';
        for(int x=0;x<b.length();x++){
            if((b.length()-1)/2==x){
                cout<<'+';continue;
            }
            cout<<'-';
        }cout<<"o\n";
        cout<<'|'<<b<<"|\n";
        cout<<'o';
        for(int x=0;x<b.length();x++){
            if((b.length()-1)/2==x){
                cout<<'+';continue;
            }
            cout<<'-';
        }cout<<"o";
    }
    return 0;
}