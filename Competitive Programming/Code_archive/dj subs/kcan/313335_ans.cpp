// ans.cpp 3 Jan 18, 17:24:32 100 0.58 Judging completed in 3.387s on AWS Oregon.
using namespace std;
int arr[10][8];
int main(){
    char a[11];
    int n,k,b;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    for(int x=0;x<n;x++){
        __builtin_scanf("%s",&a);
        for(int y=0;y<__builtin_strlen(a);y++){
            b=(int)a[y];
            for(int z=0;z<8;z++){
                if( (1<<z)&b)arr[y][z]++;
            }
        }
    }
    for(int x=0;x<10;x++){
        b=0;
        for(int y=0;y<8;y++){
            if((arr[x][y]%k)!=0)b=b|(1<<y);
        }
        if(b==0)break;
        __builtin_printf("%c",b);
    }
    return 0;
}