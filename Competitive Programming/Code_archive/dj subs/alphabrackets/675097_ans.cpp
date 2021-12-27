// ans.cpp 7 Jan 20, 20:54:14 100 0.37 Judging completed in 5.66s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans=0;
int cnt[2000005][26];
//cnt[x] is after taking the xth letter (1-indexed)...
stack<pair<int,int> > v;//iterator, count...
stack<char> v2;

char c;
bool diff;

inline char cmp(int it1,int it2){
	diff=false;
	for(int x=0;x<26;x++){
		if(cnt[it1][x]!=cnt[it2][x]){
			diff=true;
			if(cnt[it1][x]>cnt[it2][x])return '>';
		}
	}
	if(diff==false)return '=';
	return '<';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	cin>>s;
	v.push(make_pair(0,1));
	for(int x=0;x<s.length();x++){
		for(int i=0;i<26;i++){
			cnt[x+1][i]=cnt[x][i];
		}
		if(s[x]-'A'<26){//uppercase
			cnt[x+1][s[x]-'A']++;
			v2.push(s[x]);
		}else{
			cnt[x+1][s[x]-'a']--;
			if(v2.size()==0 || v2.top()!=s[x]-32){
			    while(v.size()>0){v.pop();}
				//v.clear();
				//v.push_back(make_pair(x+1,1));
				while(v2.size()>0){v2.pop();}
				//v2.clear();
				for(int i=0;i<26;i++){
					cnt[x+1][i]=0;//reset
				}
			}else v2.pop();
		}
		
		if(v.size()==0){
			v.push(make_pair(x+1,1));
			continue;
		}
		while(v.size()>0){
			c=cmp(v.top().first,x+1);
			if(c=='='){
				ans+=v.top().second;
				v.top().second++;
				break;
			}else if(c=='<'){
				v.push(make_pair(x+1,1));
				break;
			}else{
				v.pop();
			}
		}
	}
	cout<<ans;
	return 0;
}