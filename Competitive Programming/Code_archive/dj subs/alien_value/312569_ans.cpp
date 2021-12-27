// ans.cpp 1 Jan 18, 16:20:07 100 0 Judging completed in 5.037s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll m=1000000007;
string diff;
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
ll ipow(ll base,ll exponent){
    base%=m;
    ll result=1;
    while(exponent){
        if (exponent%2==1) result *= base;
        base *= base;
        base %= m;
        result %= m;
        exponent >>= 1;
    }
    return result;
}
string subtract(string a,string b){//returns a-b
	int c=a.length()-1,ne;//new value
	bool owe=false;
	for(int x=b.length()-1;c>=0;x--){
		ne=a[c]-'0';
		if(x>=0){
		    ne-=(b[x]-'0');
		}else{
		    if(!owe)break;
		}
		if(owe)ne--;
		if(ne<0){
			owe=true;
			ne+=10;
		}else{
			owe=false;
		}
		a[c]=ne+'0';
		
		c--;
	}
	while(a[0]=='0'&&a.length()>1){
		a.erase(0,1);
	}
	return a;
}
ll mod(string n,ll m){
	ll nex=0,current=0;
    bool broke=false;
    while(true){
        while(current<m){
            if(nex>=n.length()){
                broke=true;
                break;
            }
            current*=10;
            current+=n[nex]-'0';
            nex++;
        }
        if(broke){
            return current;
            break;
        }
        current%=m;
    }
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
ll sumi(string s,string e){
	if(( ((s[s.length()-1]-'0')+(e[e.length()-1]-'0'))%2)==0){
		//return((((((s+e)/2)%m)*((e-s+1)%m)))%m);
		return((mod(half(sum(s,e)),m)*mod(sum(diff,"1"),m))%m);
	}else{
		//return(((((s+e)%m)*(((e-s+1)/2)%m)))%m);
		return((mod(sum(s,e),m)*mod(half(sum(diff,"1")),m))%m);
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string p,q;
    cin>>p>>q;
    diff=subtract(q,p);
    cout<<(ipow(2,mod(diff,(m-1)))*( sumi(p,q)%m))%m;
    return 0;
}