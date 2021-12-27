// ans.cpp 7 Dec 16, 18:04:12 0 2.01 Judging completed in 9.849s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int ipow(int a,int b){
    int ans=1;
    for(int x=0;x<b;x++){
        ans*=a;
    }
    return ans;
}
bool unlucky(int y){
    bool a=false;
    int y_length,b;
    for(int x=1;x<a;x++){
        if(ipow(10,x)>y)y_length=x;
    }
    for(int x=y_length-1;x>=0;x++){
        b=(y/ipow(10,x))%10;
        if(b==4) return true;
        if(b==3 && a==true) return true;
        if(b==1) a=true;
        else a=false;
    }
    return false;
}
int main() {
    int n;
    short int t;
    uint64_t x,abc;
    cin>>n;
    uint64_t output[n];
    for(int a=0;a<n;a++){
        cin>>t>>x;
        if(t==1){
            if(unlucky(x)){
                output[a]=-1;
            }else{
                abc=0;
                for(uint64_t b=1;b<=x;b++){
                    if(unlucky(b)) abc++;
                }
                output[a]=x-abc;
            }
        }else{
            abc=0;
            for(uint64_t b=1;b<=x;b++){
                if(unlucky(b))abc++;
            }
            output[a]=abc+x;
        }
    }
    for(int a=0;a<n;a++){
        cout<<output[a]<<'\n';
    }
    return 0;
}