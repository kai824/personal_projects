// ans.cpp 11 Jan 17, 16:17:48 0 0 Judging completed in 4.957s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
    }
    sort(b,b+a);
    if(a%2==1){
        cout<<b[a/2];
    }else{
        cout<<(b[(a/2)-1]+b[a/2])/2;
    }
    return 0;
}