// ans.cpp 2 Apr 19, 08:13:50 100 0.1 Judging completed in 5.709s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool less_than(string a,string b){
	if(a.length()==b.length()){
		return(a<b);
	}else{
		return(a.length()<b.length());
	}
}

string sum(string a,string b){
    int ne,carry_over=0,c;
    if(a.length()<b.length())swap(a,b);
    c=a.length()-1;
    for(int x=b.length()-1;c>=0;x--){
        ne=a[c]-'0';
        if(x>=0)ne+=b[x]-'0';
        else if(carry_over==0)break;
        ne+=carry_over;
        carry_over=ne/10;
        a[c]=(ne%10)+'0';
        c--;
    }
    if(carry_over!=0){
        a=" "+a;
        a[0]=carry_over+'0';
    }
    return a;
}

string multiply(string a,string b){
	string zeroes="",ans="0",cur;
	int c;
	for(int x=b.length()-1;x>=0;x--){
		cur="";
		c=0;
		for(int y=a.length()-1;y>=0;y--){
			c+=( (a[y]-'0')*(b[x]-'0') );
			cur=" "+cur;
			cur[0]=(c%10)+'0';
			c/=10;
		}
		if(c!=0){
			cur=" "+cur;
			cur[0]=c+'0';
		}
		if(ans=="0"){
			ans=cur;
		}else{
			ans=sum(ans,cur+zeroes);
		}
		zeroes=zeroes+"0";
	}
	return ans;
}

string half(string a){
	bool b=false;
	int c,d;
	for(int x=0;x<a.length();x++){
		c=a[x]-'0';
		//if(b)c+=5;
		//b=((c%2)==1);
		d=c/2;
		if(b)d+=5;
		b=((c%2)==1);
		a[x]=d+'0';
	}
	if(a[0]=='0')a.erase(0,1);
	return a;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a,lo="1",hi,mid;
	cin>>a;
	hi=a;
	while(less_than(lo,hi)){
		mid=half(sum(lo,hi));//mid=(lo+hi)/2
		if( less_than(multiply(mid,mid),a) ){
			lo=sum(mid,"1");
		}else{
			hi=mid;
		}
	}
	cout<<lo;
	return 0;
}