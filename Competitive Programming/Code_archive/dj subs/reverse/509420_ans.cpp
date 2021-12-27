// ans.cpp 22 Mar 19, 16:05:28 0 1 Judging completed in 4.673s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s,word="",to_add=" ";
	int start=0,it;
	getline(cin,s);
	for(int x=0;x<s.length();x++){
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
			word=s[x]+word;
		}
	}
	if(word!=""){
		it=0;
			for(int y=start;y<s.length();y++){
				if(isupper(s[y])){
					word[it]=toupper(word[it]);
				}else{
					word[it]=tolower(word[it]);
				}
				cout<<s[y]<<word[it]<<'\n';
				it++;
			}
			cout<<word;
			word="";
	}
	return 0;
}