// ans.cpp 18 Jun 19, 00:22:15 0 0 Judging completed in 4.297s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b;
    FILE * f;
    ios::sync_with_stdio(false);
    f=fopen("tmp.txt","wb");
    while(cin>>a){
        fprintf(f,"%d ",a);
        b+=floor(log10(a))+1;
        if(b>=2000000)break;
    }
    return 0;
}