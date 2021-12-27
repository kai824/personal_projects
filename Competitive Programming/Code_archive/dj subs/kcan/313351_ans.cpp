// ans.cpp 3 Jan 18, 18:08:00 100 0.55 Judging completed in 3.24s on AWS Oregon.
int arr[10][7];
main(){
    char a[10];
    int n,k,x;
    short int b,y,z;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    for(x=0;x<n;x++){
        __builtin_scanf("%s",&a);
        for(y=0;y<__builtin_strlen(a);y++){
            b=(int)a[y];
            for(z=0;z<7;z++){
                if(((1<<z)&b)==0)arr[y][z]++;
            }
        }
    }
    for(x=0;x<10;x++){
        b=0;
        for(y=0;y<7;y++){
            if((arr[x][y]%k)==0)b=b|(1<<y);
        }
        if(b==127)break;
        __builtin_printf("%c",b);
    }
}