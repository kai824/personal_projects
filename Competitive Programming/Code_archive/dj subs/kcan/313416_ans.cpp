// ans.cpp 3 Jan 18, 21:00:01 100 0.41 Judging completed in 4.178s on AWS Oregon.
int arr[10][7];
main(){
    char a[10];
    int n,k,x;
    short int b,y,z;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    for(x=0;x<n;x++){
        __builtin_scanf("%s",&a);
        b=__builtin_strlen(a);
        for(y=0;y<b;y++){
            for(z=0;z<7;z++){
                if( (1<<z)&a[y])arr[y][z]++;
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