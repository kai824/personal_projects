// ans.cpp 8 Feb 20, 10:29:00 0 4.01 Judging completed in 10.197s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/

string s,t;int a,b;
bool prefix;
vector<pair<string,int> > children[300005];
char c;

inline void cmp(int aa,string& s2){
	prefix=false;
	for(int x=0;true;x++){
		if(aa+x>=b && x>=s2.length()){
			c='=';return;
		}
		if(aa+x>=b){//first string is a prefix of second one...
			c='<';
			prefix=true;
			return;
		}else if(x>=s2.length()){
			c='>';
			prefix=true;
			return;
		}
		if(s[aa+x]<s2[x]){
			c='<';
			return;
		}else if(s[aa+x]>s2[x]){
			c='>';
			return;
		}
	}
}

int dfs(int node,int cur_it,bool finding_max=false){
	int lo,hi,mid;
	lo=0;hi=children[node].size()-1;
	if(children[node].size()==0){
		if(node==0)return -1;
		return node;
	}
	if(finding_max){
		lo=children[node].back().second;
		return dfs(lo,-1,true);//who cares about cur_it anymore
	}
	cmp(cur_it,children[node][0].first);
	if(c=='<'){
		return -1;
	}
	cmp(cur_it,children[node].back().first);
	while(lo<hi){
		mid=hi-(hi-lo)/2;
		cmp(cur_it,children[node][mid].first);
		if(c=='='){
			lo=mid;
		}else if(c=='>'){
			lo=mid;
		}else{
			hi=mid-1;
		}
	}
	cmp(cur_it,children[node][lo].first);
	if(prefix!=true){//lexicographically smaller already...
		mid=dfs(children[node][lo].second,cur_it+children[node][lo].first.length(),true);
	}else mid=dfs(children[node][lo].second,cur_it+children[node][lo].first.length());
	if(mid==-1)return children[node][lo].second;
	return mid;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>s;//full string...
	int n,q,p;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>p>>t;//copy speaker p, add t to the end...
		children[p].push_back(make_pair(t,x+1));
	}
	for(int x=0;x<n;x++){
		if(children[x].size()>0)
		sort(children[x].begin(),children[x].end());
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b;
		a--;
		cout<<dfs(0,a)<<'\n';
	}
	return 0;
}

/*
weneedtopassanewhealthcarebill
5
0 russian
0 as
2 set
0 blue
4 donkey
4
10 12
27 30
1 30
24 26
*/