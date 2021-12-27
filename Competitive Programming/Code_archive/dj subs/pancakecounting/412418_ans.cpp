// ans.cpp 14 Nov 18, 10:22:50 100 0.32 Judging completed in 3.901s on AWS Oregon.
#include <iostream>
using namespace std;
#pragma Ospace
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    FILE * f;
    ios::sync_with_stdio(false);
    f=fopen("tmp.txt","wb");
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