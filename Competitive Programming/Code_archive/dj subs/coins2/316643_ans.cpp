// ans.cpp 17 Jan 18, 08:20:23 0 2.97 Judging completed in 13.009s on AWS Oregon.
#include <iostream>
#include <bitset>
using namespace std;
bitset<30000005>bs;
int ans;bool neg;
void getint(){
	char a;
	a=getchar();
	while(a==' '||a=='\t'||a=='\n'){
		a=getchar();
	}
	ans=0;neg=false;
	while(true){
		if(a=='-'){
			neg=true;
		}else if(isdigit(a)){
			ans*=10;
			ans+=a-'0';
		}else{
			break;
		}
		a=getchar(); 
	}
	if(neg)ans=-ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        int a,b;
        getint();
        swap(a,ans);
        getint();swap(b,ans);
        bs[a]=!bs[a];
        bs[b+1]=!bs[b+1];
    }
    bool current=0;
    for(int x=0;x<n;x++){
        current^=bs[x];
        cout<<current;
    }
    return 0;
}