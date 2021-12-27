// ans.cpp 9 Jul 17, 16:07:21 0 0.14 Judging completed in 9.227s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b;
    cin>>n;
    string arr[n];
    bool b1,b2;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int x=0;x<n;x++){
        b1=false;b2=false;
        for(int y=0;y<n;y++){
            if(arr[x][y]=='Q'){
                if(b1){
                    cout<<"Attack";
                    return 0;
                }else{
                    b1=true;
                }
            }
            if(arr[y][x]=='Q'){
                if(b2){
                    cout<<"Attack";
                    return 0;
                }
            }
        }
    }
    for(int x=0;x<n;x++){
        a=0;b=x;
        b1=false;
        b2=false;
        while(b<n){//since a<=b no matter what
            if(arr[a][b]=='Q'){
                if(b1){
                    cout<<"Attack";
                    return 0;
                }else{
                    b1=true;
                }
            }
            if(arr[b][a]=='Q'){
                if(b2){
                    cout<<"Attack";
                    return 0;
                }else{
                    b2=true;
                }
            }
            a++;b++;
        }
    }
    for(int x=0;x<n;x++){
        a=0;b=x;
        b1=false;
        while(a<n && b>=0){
            if(arr[a][b]=='Q'){
                if(b1){
                    cout<<"Attack";
                    return 0;
                }else{
                    b1=true;
                }
            }
            a++;b--;
        }
    }
    for(int x=0;x<n;x++){
        a=n;b=x;
        b1=false;
        while(a<n && b>=0){
            if(arr[a][b]=='Q'){
                if(b1){
                    cout<<"Attack";
                    return 0;
                }else{
                    b1=true;
                }
            }
            a--;b++;
        }
    }
    cout<<"No Attack";
    return 0;
}