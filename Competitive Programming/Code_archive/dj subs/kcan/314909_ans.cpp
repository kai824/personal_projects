// ans.cpp 9 Jan 18, 21:26:06 30 0.58 Judging completed in 4.006s on AWS Oregon.
#include<bitset>
std::bitset<17>bbbbb;
struct myint{
    std::bitset<17> v;
    void add(std::bitset<17>s){
        if(s==bbbbb)return;
        std::bitset<17>b=(v&s)<<1;
        v^=s;
        add(b);
    }
    int toint(){
        int ans=0;
        for(int x=16;x>=0;x--){
            if(v[x]==0)continue;
            ans+=(1<<(16-x));
        }
        return ans;
    }
};
myint arr[10][7];
std::bitset<17> one;
main(){
    one[16]=1;
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
                if( (1<<z)&a[y])arr[y][z].add(one);
            }
        }
    }
    for(x=0;x<10;x++){
        b=0;
        for(y=0;y<7;y++){
            if((arr[x][y].toint()%k)!=0)b=b|(1<<y);
        }
        if(b==0)break;
        __builtin_printf("%c",b);
    }
}