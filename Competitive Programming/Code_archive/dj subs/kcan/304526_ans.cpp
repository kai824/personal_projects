// ans.cpp 24 Dec 17, 20:27:33 0 0 Compilation failed on AWS Oregon.
#include<algorithm>
int arr[14];
main() {
    int n,k;
    __builtin_scanf("%d",&n);
    __builtin_scanf("%d",&k);
    if(k==2){
        #include<iostream>
        #include<string>
        std::string a;
        for(int x=0;x<n;x++){
        	std::cin>>a;
        	for(int y=0;y<a.length();y++){
        		arr[y] ^= a[y];
        	}
        }
        for(int x=0;x<14;x++){
        	std::cout<<(char)arr[x];
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