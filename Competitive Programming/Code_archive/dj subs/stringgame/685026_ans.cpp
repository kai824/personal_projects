// ans.cpp 24 Jan 20, 16:55:26 14 0 Judging completed in 3.762s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
int main() {
    int n,s1,s2;
		s1=s2=n=0;
    char c;
		while(true){
			c=getchar_unlocked();
			if(c=='\n')break;
			n*=10;
			n+=c-'0';
		}
    for(int x=0;x<n;x++){
        c=tolower(getchar_unlocked());
        if(((n-x)%2)==0){
					s1+=(1+c-'a')*((n-x)/2);
					s2+=(1+c-'a')*((n-x)/2);
				}else{
					s1+=(1+c-'a')*((n-x)/2);
					s2+=(1+c-'a')*((n-x+1)/2);
				}
    }
    cout<<s1<<' '<<s2;
    return 0;
}