// ans.cpp 4 Jun 18, 09:33:23 0 0 Compilation failed on AWS Oregon.
using namespace std;
long long arr[167000];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    __builtin_scanf("%d",&n);
    int a;
    for(int x=0;x<n;x++){
        __builtin_scanf("%d",&a);
        for(int y=0;y<10;y++){
            if((a&(1<<y))!=0) arr[x/6]|=1<<((x%6)+y);
        }
    }
    int k;
    __builtin_scanf("%d",&k);
    for(int x=0;x<n;x++){
        a=0;
        for(int y=0;y<10;y++){
            if((arr[x/6]&(1<<((x%6)+y)))!=0){
                a&=1<<y;
            }
        }
        __builtin_printf("%d\n",a);
    }
    return 0;
}