// ans.cpp 26 May 18, 22:01:25 100 0.33 Judging completed in 3.839s on AWS Oregon.
#include <iostream>
using namespace std;
#pragma O3
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