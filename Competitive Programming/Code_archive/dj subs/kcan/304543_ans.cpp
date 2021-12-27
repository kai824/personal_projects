// ans.cpp 24 Dec 17, 20:35:01 45 0.12 Judging completed in 11.535s on AWS Oregon.
#include<algorithm>
int arr[14];
main() {
    int n,k;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    if(k==2){
        char a[15];
        for(int x=0;x<n;x++){
        	__builtin_scanf("%s",a);
        	for(int y=0;y<__builtin_strlen(a);y++){
        		arr[y] ^= a[y];
        	}
        }
        for(int x=0;x<14;x++){
        	//std::cout<<(char)arr[x];
        	__builtin_printf("%c",( (char)arr[x] ));
        }
    }else{
        int ar[n];
        for(int x=0;x<n;x++){
            __builtin_scanf("%d",&ar[x]);
        }
        std::sort(ar,ar+n);
        int cnt=1;
        for(int x=1;x<n;x++){
            if(ar[x]==ar[x-1]){
                cnt++;
            }else{
                if(cnt!=k){
                    __builtin_printf("%d",ar[x-1]);
                    return 0;
                }
                cnt=1;
            }
        }
        __builtin_printf("%d",ar[n-1]);
    }
}