// ans.cpp 1 Feb 17, 19:16:29 100 0.15 Judging completed in 4.833s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	if(a.length()!=b.length()){
		return(a.length()<b.length());
	}else{
		return(a<b);
	}
}
int main() {
    int a;
    cin>>a;
    string b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
    }sort(b,b+a,cmp);
    for(int x=0;x<a;x++){
        cout<<b[x];
        if(x+1<a)cout<<' ';
    }
    return 0;
}