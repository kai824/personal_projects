#include "bits/stdc++.h"
using namespace std;

#define int int64_t

int tc,k,d,c;
bool exist[10];
string s,s2;

void main2(){
	int carry_over=0;
	for(int x=s.length()-1;x>=0;x--){
		d=s[x]-'0'-1;//treat as a base 9 number...
		c=(k%9);k/=9;
		d+=c+carry_over;
		carry_over=d/9;
		s[x]='1'+(d%9);
	}
	k+=carry_over;
	s2="";
	while(k>0){
		s2= char((k%9)+'0') +s2;
		if(s2[0]=='0'){
			k-=9;
			s2[0]='9';
		}
		k/=9;
	}
	cout<<s2;
	cout<<s<<'\n';
}

void inc(){//increment s...
	for(int x=s.length()-1;x>=0;x--){
		if(s[x]=='9'){
			s[x]='0';
			continue;
		}
		s[x]++;
		return;
	}
	s="1"+s;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
		cin>>tc;
		while(tc--){
			cin>>s>>k;
			if(k>1){
				main2();
				continue;
			}
			for(int i=0;i<10;i++)exist[i]=false;
			for(int i=0;i<s.length();i++){
				exist[s[i]-'0']=true;
			}
			for(d=0;d<10;d++){
				if(exist[d]==0){
					break;
				}
			}
			while(true){
				inc();
				for(int i=0;i<10;i++)exist[i]=false;
				for(int i=0;i<s.length();i++){
					exist[s[i]-'0']=true;
				}
				for(c=0;c<10;c++){
					if(exist[c]==0){
						break;
					}
				}
				if(c==d)break;
			}
			cout<<s<<'\n';
		}
    return 0;
}
