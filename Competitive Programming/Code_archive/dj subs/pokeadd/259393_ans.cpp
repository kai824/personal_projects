// ans.cpp 17 Nov 17, 15:43:35 70 0 Judging completed in 2.458s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c;
    
    if(c==2){
        for(int x=0;x<a+b;x++){
            for(int y=0;y<5e9;y++){a=a;}
        }
        a^=b;
        vector<int> v;
        while(a>0){
            v.push_back(a&1);
            a/=2;
        }
        while(v.size()>0){
            cout<<v.back();v.pop_back();
        }
        return 0;
    }
    
    vector<int> v;
    while(a>0&&b>0){
        d=a%c;
        d+=b%c;
        d%=c;
        v.push_back(d);
        a/=c;
        b/=c;
    }
    bool started=false;
    while(v.size()>0){
        if(v.back()==0){
        	if(started){
        		cout<<v.back();
        	}
        }else{
        	cout<<v.back();
        	started=true;
        }
        v.pop_back();
    }
    if(started==false){
    	cout<<"0";
    }
    return 0;
}