// ans.cpp 9 Dec 16, 20:55:22 0 1 Judging completed in 4.311s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,f1,f2;
    cin>>a;
    int output[a];
    for(int x=0;x<a;x++){
        cin>>b>>c;
        f1=0;
        f2=1;
        if(b==0)output[x]=f1;
        else if(b==1)output[x]=f2;
        else{
            for(int y=0;1<a;y++){
                swap(f1,f2);
                f2=(f1+f2)%c;
            }
            output[x]=f2;
        }
    }
    for(int x=0;x<a;x++){
        cout<<output[x]<<'\n';
    }
    return 0;
}