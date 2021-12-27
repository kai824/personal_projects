// ans.cpp 24 Dec 17, 20:32:53 45 0.22 Judging completed in 9.592s on AWS Oregon.
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
        int arr[n];
        for(int x=0;x<n;x++){
            __builtin_scanf("%d",&arr[x]);
        }
        std::sort(arr,arr+n);
        int cnt=1;
        for(int x=1;x<n;x++){
            if(arr[x]==arr[x-1]){
                cnt++;
            }else{
                if(cnt!=k){
                    __builtin_printf("%d",arr[x-1]);
                    return 0;
                }
                cnt=1;
            }
        }
    }
}