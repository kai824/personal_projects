// ans.cpp 28 Dec 19, 16:10:58 30 0.09 Judging completed in 4.76s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int convert(string a){
    int ans=0;
    for(int x=0;x<a.length();x++){
        ans*=10;ans+=a[x]-'0';
    }
    return ans;
}

string tos(int a){
	string ans="", t=" ";
	while(a>0){
		t[0]=(a%10)+'0';
		ans+=t;
		a/=10;
	}
	return ans;//reverses it too...
}

int main() {
    int n,aa,bb;
    long long ans=0;
    cin>>n;
    string a,b,c;
    cin>>a>>c;
    if(a.length()<7){
        aa=convert(a);
        for(int x=0;x<=aa;x++){
            if(c>=tos(x)){
				ans++;
			}
        }
		cout<<ans;
        return 0;
    }
    b=c;
    bool carry=true;
    for(int x=n-1;x>=0;x--){
        if(carry){
            if(b[x]=='9'){
                b[x]='0';
                continue;
            }
            b[x]++;
            carry=false;
            break;
        }
    }
    for(int x=0;x<n;x++){
        ans*=10;ans+=b[x]-'0';
        ans%=(1000000007);
    }
    cout<<ans;
    return 0;
}