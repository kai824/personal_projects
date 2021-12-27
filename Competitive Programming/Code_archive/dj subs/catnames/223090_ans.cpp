// ans.cpp 17 Oct 17, 17:05:51 0 0.08 Judging completed in 5.031s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void output(ll input,ll b){//the number in base 10, the desired base
    string ans="",p=" ";
    ll c;
    bool br=false;
    while(input>0){
    	c=input%b;
    	input/=b;
    	if(br==false){
    		br=true;
    	}else c--;
    	if(c<10){
    		p[0]=(char)(c+97);
    		//p[0]=c+'0';
    	}
    	ans=p+ans;
    }
    if(ans=="")ans="a";
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,k;
    string ans;
    cin>>t;
    while(t--){
        cin>>n>>k;
        output(n-1,k);
    }
    return 0;
}