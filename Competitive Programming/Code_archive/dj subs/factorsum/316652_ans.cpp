// ans.cpp 17 Jan 18, 08:57:24 40 0.43 Judging completed in 3.862s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string str(int x){
    string ans="";
    while(x>0){
        ans=" "+ans;
        ans[0]=(x%10)+'0';
        x/=10;
    }
    return ans;
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
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    unsigned long long n;
    while(t--){
        cin>>n;
        string ans="0";
        for(int x=1;x*x<=n;x++){
            if((n%x)!=0)continue;
            ans=sum(ans,str(x));
            if(x*x==n)continue;
            ans=sum(ans,str(n/x));
        }
        cout<<ans<<'\n';
    }
    return 0;
}