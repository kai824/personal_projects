// ans.cpp 19 Jun 18, 09:29:21 100 0.32 Judging completed in 5.453s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma Ospace
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    FILE * f;
    f=fopen("tmp.txt","w");
    int n,a,k;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>k;
        fprintf(f,"%d\n",k);
    }
    cin>>k;
    fclose(f);
    f=fopen("tmp.txt","r");
    for(int x=0;x<n;x++){
        fscanf(f,"%d",&a);
        cout<<a+k<<'\n';
    }
    fclose(f);
    system("rm tmp.txt");
    return 0;
}