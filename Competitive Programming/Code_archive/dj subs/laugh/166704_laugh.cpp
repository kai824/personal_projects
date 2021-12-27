// laugh.cpp 2 Dec 16, 19:26:37 0 0 Judging completed in 7.418s on AWS Ireland.
#include "laugh.h"
#include <bits/stdc++.h>
using namespace std;

int longest_laugh(string s) {
    int ans=0,current=0,a=-1;//a is 0 when it's h, 1 when it's a
    for(int x=0;x<s.length();x++){
        if(s[x]=='a' &&(a==0 || a==-1)){
            current++;
            a=1;
            ans=max(ans,current);
        }else if(s[x]=='h' &&(a==1 || a==-1)){
            current++;
            a=0;
            ans=max(ans,current);
        }else{
            a=-1;
            current=0;
        }
    }
	return ans;
}