// ans.cpp 1 Feb 18, 18:26:19 0 2.44 Judging completed in 13.013s on AWS Oregon.
#include <iostream>
using namespace std;
bool ft[30000005];
int s,e,n,q;//a counts the number of starting markers, b counts the number of ending markers...
int ls(int x){
	return(x&(-x));
}
void rupdate(int a,int b){
	for(;a<=n;a+=ls(a)){
		ft[a]^=1;
	}
	b++;
	for(;b<=n;b+=ls(b)){
		ft[b]^=1;
	}
}
int query(int x){
	int sum=0;
	for(;x;x-=ls(x)){
		sum^=ft[x];
	}
	return sum;
}
bool flag=0;

char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    for(int x=0;x<q;x++){
    	s=get();e=get();
    	rupdate(s+1,e+1);//change to 1-indexed...
    	if(flag)break;
    }
    for(int x=1;x<=n;x++){
    	if((query(x)%2)==0){
    		//coin x flipped an even number of times...
    		cout<<0;
    	}else{
    		//coin x flipped an odd number of times...
    		cout<<1;
    	}
    }
    return 0;
}