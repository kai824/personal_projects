// ans.cpp 13 Aug 17, 17:38:41 80 0 Judging completed in 7.338s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
char arr[105][105];
int main() {
    int a,b=-1,c;
    string s;
    bool adding=true;
    cin>>a>>s;
    for(int x=0;x<s.length()+5;x++){
    	if(adding){
    		b++;
    		if(b>=a){
    			b-=2;
    			adding=false;
    		}
    	}else{
    		b--;
    		if(b<0){
    			b+=2;
    			adding=true;
    		}
    	}
    	arr[x][b]='.';
    }
    b=0;
    for(int x=0;x<a;x++){
    	for(int y=0;y<s.length();y++){
    		if(arr[y][x]=='.'){
    			arr[y][x]=s[b];
    			b++;
    		}
    	}
    }
    b=-1;
    adding=true;
    for(int x=0;x<s.length();x++){
    	if(adding){
    		b++;
    		if(b>=a){
    			b-=2;
    			adding=false;
    		}
    	}else{
    		b--;
    		if(b<0){
    			b+=2;
    			adding=true;
    		}
    	}
    	cout<<arr[x][b];
    }
    return 0;
}