// ans.cpp 23 Dec 17, 09:47:24 40 0.26 Judging completed in 6.323s on AWS Oregon.
using namespace std;
int ar2[111115];
int main() {
    int n,a,k,nn;
    __builtin_scanf("%d",&n);
    char arr[n];
    for(int x=0;x<n;x++){
        __builtin_scanf("%d",&a);
        arr[x]=(char)(a%101);
        //ar2[x]=(a/101)+'0';
        ar2[x/9]=(ar2[x/9]*10)+(a/101);
    }
    for(int x=n;(1==1);x++){
        if(ar2[x/9]==0)break;
        ar2[x/9]*=10;
    }
    __builtin_scanf("%d",&k);
    for(int x=0;x<n;x++){
        nn=ar2[x/9];
        for(int y=(x%9);y<8;y++){
            nn/=10;
        }
        nn%=10;
        a=101*(nn);
        a+=(int)(arr[x]);
        __builtin_printf("%d\n",(a+k));
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}