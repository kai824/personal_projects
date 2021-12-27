// laugh.cpp 16 Apr 17, 14:50:11 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
#include<"laugh.h">
using namespace std;


int longest_laugh(string s){
	int sum=1,big=0,i;
	for (i=1;i<s.size();i++){
		if (s[i]=='h'){
			if (s[i-1]=='a')sum++;
			else {
				
				sum=1;
				
			}
		}
		else if (s[i]=='a'){
			if (s[i-1]=='h')sum++;
			else {
				
				sum=1;
				
			}
		}
		big=max(big,sum);
	
	}
	return big;
}