// ans.cpp 15 Oct 17, 00:06:26 100 0 Judging completed in 5.691s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
vector<int>p;
ll base,c=1;
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
bool test(int a){
    for(int x=0;x<p.size();x++){
        if(a==p[x]){
        	cout<<a<<'\n';return true;
        }
    }
    return false;
}
int main() {
    string t;
    int a,b;
    string aa;
    bool e=false;
    cin>>aa>>t;
    base=2;
    a=to10(aa);
    for(int x=0;x<30;x++){
    	if(x+1>aa.size())break;
        if((c&a)>0){
            if(a-c<1000000000)p.push_back(a-c);
        }else{
            if(a+c<1000000000)p.push_back(a+c);
        }
        c*=2;
    }
    c=1;
    base=3;
    b=to10(t);
    for(int x=1;x<=19;x++){
    	if(x>t.size())break;
        if(t[t.length()-x]=='0'){
            e=test(b+c)||e;
            e=test(b+c+c)||e;
        }
        if(t[t.length()-x]=='1'){
            e=e||test(b+c);
            e=e||test(b-c);
        }
        if(t[t.length()-x]=='2'){
            e=e||test(b-c);
            e=e||test(b-c-c);
        }
        if(e)break;
        c*=3;
    }
    return 0;
}