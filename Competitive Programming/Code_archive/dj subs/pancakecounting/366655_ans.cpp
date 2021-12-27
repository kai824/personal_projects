// ans.cpp 26 May 18, 13:51:10 40 0 Judging completed in 4.885s on AWS Oregon.
#include <bitset>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
    cin>>n;
    bitset<10000100>arr;
    for(int x=0;x<n;x++){
        cin>>a;
        for(int y=0;y<10;y++){
            if(((1<<y)&a)!=0){
                arr.set((x*10) + y);
            }else arr.set((x*10) + y , 0);
        }
    }
    cin>>k;
    for(int x=0;x<n;x++){
        a=0;
        for(int y=0;y<10;y++){
            if(arr.test((x*10) + y)==1){
                a+=(1<<y);
            }
        }
        cout<<a+k<<'\n';
    }
    return 0;
}