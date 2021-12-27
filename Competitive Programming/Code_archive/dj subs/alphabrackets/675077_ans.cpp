// ans.cpp 7 Jan 20, 20:33:58 100 0.33 Judging completed in 5.328s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans=0;
int cnt[2000005][26];
//cnt[x] is after taking the xth letter (1-indexed)...
vector<pair<int,int> > v;//iterator, count...
vector<char> v2;

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
	v.push_back(make_pair(0,1));
	for(int x=0;x<s.length();x++){
		for(int i=0;i<26;i++){
			cnt[x+1][i]=cnt[x][i];
		}
		if(s[x]-'A'<26){//uppercase
			cnt[x+1][s[x]-'A']++;
			v2.push_back(s[x]);
		}else{
			cnt[x+1][s[x]-'a']--;
			if(v2.size()==0 || v2.back()!=s[x]-32){
				v.clear();
				//v.push_back(make_pair(x+1,1));
				v2.clear();
				for(int i=0;i<26;i++){
					cnt[x+1][i]=0;//reset
				}
			}else v2.pop_back();
		}
		
		if(v.size()==0){
			v.push_back(make_pair(x+1,1));
			continue;
		}
		while(v.size()>0){
			c=cmp(v.back().first,x+1);
			if(c=='='){
				ans+=v.back().second;
				v.back().second++;
				break;
			}else if(c=='<'){
				v.push_back(make_pair(x+1,1));
				break;
			}else{
				v.pop_back();
			}
		}
	}
	cout<<ans;
	return 0;
}