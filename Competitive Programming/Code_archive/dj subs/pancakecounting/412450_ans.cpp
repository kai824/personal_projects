// ans.cpp 14 Nov 18, 10:26:41 100 0.31 Judging completed in 3.822s on AWS Oregon.
#include <iostream>
using namespace std;
#pragma Ospace

void main2(int n){
    int arr[n],k;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    cin>>k;
    for(int x=0;x<n;x++){
        cout<<arr[x]+k<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,k;
    cin>>n;
    if(n<=10000){
        main2(n);
        return 0;
    }
    FILE * f;
    ios::sync_with_stdio(false);
    f=fopen("tmp.txt","wb");
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