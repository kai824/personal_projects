// ans.cpp 11 Mar 18, 23:11:33 100 0.53 Judging completed in 3.03s on AWS Oregon.
#pragma Ospace
using namespace std;
int arr[10][7],x,y,z;
main(){
    char a[10];
    int n,k;
    short int b;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    for(x=0;x<n;x++){
        __builtin_scanf("%s",&a);
        for(y=0;y<__builtin_strlen(a);y++){
            b=(int)a[y];
            for(z=0;z<7;z++){
                if( (1<<z)&b)arr[y][z]++;
            }
        }
    }
    for(x=0;x<10;x++){
        b=0;
        for(y=0;y<7;y++){
            if((arr[x][y]%k)!=0)b=b|(1<<y);
        }
        if(b==0)break;
        __builtin_printf("%c",b);
    }
}