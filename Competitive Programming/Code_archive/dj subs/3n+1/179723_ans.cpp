// ans.cpp 10 Jan 17, 20:41:15 100 0 Judging completed in 4.399s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    cout<<n;
    while(true){
        if(n==1)break;
        if(n%2==0){
            n=n/2;
        }else{
            n=3*n;
            n++;
        }
        cout<<' '<<n;
    }
    return 0;
}