// ans.cpp 1 Nov 17, 22:22:20 60 0 Judging completed in 2.614s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string output(ll input,ll b){//the number in base 10, the desired base
    string ans="",p=" ";
    ll c;
    while(input>0){
    	c=input%b;
    	input/=b;
    	if(c<10){
    		p[0]=c+'0';
    	}else{
    		p[0]=(char)(c+55);
    	}
    	ans=p+ans;
    }
    c=ans.length();
    for(int x=0;x<c;x++){
    	if(ans[x]=='0' && ans.length()>1)ans.erase(0,1);
    	else break;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a,b,base;
    string c,d,ans="";
    cin>>a>>b>>base;
    c=output(a,base);
    d=output(b,base);
    
    a=c.length()-1;
    b=d.length()-1;
    //now used as iterators
    while(a>=0 && b>=0){
        ans=" "+ans;
        if(a<0){
            ans[0]=d[b];
        }else if(b<0){
            ans[0]=c[a];
        }else{
            ans[0]=(((c[a]-'0')+(d[b]-'0'))%base)+'0';
        }
        a--;b--;
    }
    a=ans.length();
    for(int x=0;x<a;x++){
    	if((ans[x]=='0' || ans[x]=='\0') && ans.length()!=1)ans.erase(0,1);
    	else{
    		break;
    	}
    }
    cout<<ans;
    return 0;
}