// ans.cpp 1 Nov 17, 22:03:30 30 0 Judging completed in 3.019s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
string output(ll input,ll b){//the number in base 10, the desired base
    string ans="",p=" ";
    ll c;
    while(input>0){
    	c=input%b;
    	input/=b;
    	p[0]=c+'0';
    	ans=p+ans;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,base;
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
            ans[0]=( ( (c[a]-'0')+(d[b]-'0') )%base )+'0';
        }
        a--;b--;
    }
    cout<<ans;
    return 0;
}