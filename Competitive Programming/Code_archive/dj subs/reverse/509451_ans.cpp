// ans.cpp 22 Mar 19, 21:22:37 0 1 Judging completed in 4.749s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s,word="",to_add=" ";
	int start=0,it,n;
	getline(cin,s);
	n=s.length();
	for(int x=0;x<n;x++){
		if(!isalpha(s[x])){
			it=0;
			for(int y=start;y<x;y++){
				if(isupper(s[y])){
					word[it]=toupper(word[it]);
				}else{
					word[it]=tolower(word[it]);
				}
				it++;
			}
			cout<<word;
			word="";
			cout<<s[x];
			start=x+1;
		}else{
			to_add[0]=s[x];
			word=to_add+word;
		}
	}
	if(word!=""){
		it=0;
			for(int y=start;y<n;y++){
				if(isupper(s[y])){
					word[it]=toupper(word[it]);
				}else{
					word[it]=tolower(word[it]);
				}
				it++;
			}
			cout<<word;
			word="";
	}
	return 0;
}