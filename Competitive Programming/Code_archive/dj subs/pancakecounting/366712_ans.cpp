// ans.cpp 26 May 18, 21:40:22 100 0.45 Judging completed in 4.592s on AWS Oregon.
#include <iostream>
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
    //system("rm tmp.txt");
    return 0;
}