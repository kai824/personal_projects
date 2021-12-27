// ans.cpp 26 Dec 16, 22:29:39 100 0 Judging completed in 7.565s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(false);
    int ans=0,current;
    string s1,s2,working="";
    cin>>s1>>s2;
    for(int x=0;x<s1.length();){
        if(s2.find(working)!=string::npos){
        	current=working.length();
        	ans=max(ans,current);
            working=working+" ";
            working[working.length()-1]=s1[x];
            x++;
        }else{
            working.erase(0,1);
        }
    }
    current=working.length();
    if(s2.find(working)!=string::npos)ans=max(ans,current);
    cout<<ans;
    return 0;
}