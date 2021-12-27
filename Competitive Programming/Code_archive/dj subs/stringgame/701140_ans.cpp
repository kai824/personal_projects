// ans.cpp 16 Feb 20, 17:47:25 100 0 Judging completed in 3.357s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
int main() {
    long long n,s1,s2;
	s1=s2=n=0;
    char c;
		while(true){
			c=getchar_unlocked();
			if(c=='\n')break;
			n*=10;
			n+=c-'0';
		}
    for(long long x=0;x<n;x++){
        c=tolower(getchar_unlocked());
        if(((n-x)%2)==0){
					s1+=(1LL+c-'a')*((n-x)/2LL);
					s2+=(1LL+c-'a')*((n-x)/2LL);
				}else{
					s1+=(1LL+c-'a')*((n-x)/2LL);
					s2+=(1LL+c-'a')*((n-x+1LL)/2LL);
				}
    }
    cout<<s1<<' '<<s2;
    return 0;
}