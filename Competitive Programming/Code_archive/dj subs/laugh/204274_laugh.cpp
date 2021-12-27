// laugh.cpp 16 Apr 17, 14:50:28 100 0 Judging completed in 5.71s on AWS Ireland.
#include <bits/stdc++.h>
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