// ans.cpp 18 Jun 19, 00:23:36 0 0.07 Judging completed in 4.562s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b=0,c=0;
    FILE * f;
    ios::sync_with_stdio(false);
    f=fopen("tmp.txt","wb");
    while(cin>>a){
        fprintf(f,"%d ",a);
        b+=floor(log10(a))+1;
        c++;
        if(b>=2000000)break;
    }
    fclose(f);
    f=fopen("tmp.txt","r");
    for(int x=0;x<c;x++){
        fscanf(f,"%d",&a);
    }
    fclose(f);
    return 0;
}