// ans.cpp 23 Dec 17, 09:45:53 0 0 Compilation failed on AWS Oregon.
using namespace std;
int ar2[111115];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,k,nn;
    __builtin_scanf("%d",&n);
    char arr[n];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=(char)(a%101);
        //ar2[x]=(a/101)+'0';
        ar2[x/9]=(ar2[x/9]*10)+(a/101);
    }
    for(int x=n;(1==1);x++){
        if(ar2[x/9]==0)break;
        ar2[x/9]*=10;
    }
    scanf("%d",&k);
    for(int x=0;x<n;x++){
        nn=ar2[x/9];
        for(int y=(x%9);y<8;y++){
            nn/=10;
        }
        nn%=10;
        a=101*(nn);
        a+=(int)(arr[x]);
        printf("%d\n",(a+k));
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}