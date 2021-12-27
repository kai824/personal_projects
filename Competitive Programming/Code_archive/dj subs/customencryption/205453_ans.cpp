// ans.cpp 29 Apr 17, 22:03:31 0 1 Judging completed in 7.898s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
string stored;
int cs=0;//current shift
int main(){
	int ans=0;
    string a;
    bool b=false;
    cin>>a;
    a=a+" ";
    for(int x=0;x<a.length();x++){
        if(b){
            b=false;
            if(isdigit(a[x])){
                for(int y=0;y<a[x]-'0';y++){
                    stored=stored+" ";
                    stored[stored.length()-1]=a[x-1];
                }
            }else{
                stored=stored+" ";
                stored[stored.length()-1]=a[x-1];
            }
        }
        if(a[x]=='!'){
            stored=stored+"!";
        }else if(isalpha(a[x])){
            b=true;
        }
    }
    b=0;
    for(int x=stored.length()-1;x>=0;x--){
    	if(stored[x]=='!'){
    	    b=1-b;
    	}else{
    	    ans+=(((int)stored[x])-97+(b*13))%26+1;
    	}
    }
    cout<<ans;
    return 0;
}