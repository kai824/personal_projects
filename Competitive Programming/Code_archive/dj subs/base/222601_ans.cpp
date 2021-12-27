// ans.cpp 14 Oct 17, 23:29:46 100 0 Judging completed in 6.369s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll base;
ll ipow(ll a,ll b){
    ll ans=1;
    for(int x=0;x<b;x++){
        ans*=a;
    }
    return ans;
}
ll to10(string input){
    ll ans=0,cur,p=0;
    for(int x=input.length()-1;x>=0;x--){
        if(isdigit(input[x])){
            cur=input[x]-'0';
        }else{
            cur=((int)input[x])-55;
        }
        ans+=cur*(ipow(base,p));
        p++;
    }
    return ans;
}
void output(ll input,ll b){//the number in base 10, the desired base
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
    cout<<ans;
}
int main() {
    string a;
    ll c,d;
    cin>>a>>base>>c;
    output(to10(a),c);
    return 0;
}