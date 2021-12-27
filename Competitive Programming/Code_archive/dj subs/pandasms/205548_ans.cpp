// ans.cpp 30 Apr 17, 20:12:08 100 0 Judging completed in 6.501s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int ans=1,b;
    string a;
    getline(cin,a);
    for(int x=0;x<a.length();x++){
        if(isalpha(a[x])){
            b=(int)tolower(a[x])-96;
            if(b>=19){
                if(b==19 || b==26)b=4;
                else{
                    b-=1;
                    b=b%3;
                    if(b==0)b=3;
                }
            }else{
                b=b%3;
                if(b==0)b=3;
            }
            ans+=b;
            if(isupper(a[x])){
                ans++;
            }
        }else if(isdigit(a[x])){
            if(a[x]=='0'){
                ans+=2;
            }else if(a[x]=='1'){
                ans+=1;
            }else if(a[x]=='7' || a[x]=='9'){
                ans+=5;
            }else{
                ans+=4;
            }
        }else{
            ans+=2;
            if(a[x]==' ')ans--;
        }
    }
    cout<<ans;
    return 0;
}