// ans.cpp 26 May 18, 21:26:50 0 0 Compilation failed on AWS Oregon.
//#include <iostream>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    FILE * f;
    f=__builtin_fopen("tmp.txt","w");
    int n,a,k;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>k;
        __builtin_fprintf(f,"%d\n",k);
    }
    cin>>k;
    __builtin_fclose(f);
    f=__builtin_fopen("tmp.txt","r");
    for(int x=0;x<n;x++){
        __builtin_fscanf(f,"%d",&a);
        //cout<<a+k<<'\n';
        __builtin_printf("%d\n",a+k);
    }
    __builtin_fclose(f);
    //system("rm tmp.txt");
    return 0;
}