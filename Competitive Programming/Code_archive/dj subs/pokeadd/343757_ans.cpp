// ans.cpp 29 Mar 18, 10:13:10 100 0 Judging completed in 3.309s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a,b,c,d;
    cin>>a>>b>>c;
    
    if(false){
        while(true){}
    }
    
    if(c==2 && a+b>1e3){
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
    
    vector<int> aa,bb;
    if(a<b)swap(a,b);//ensure that aa is longer...
    while(a>0){
        aa.push_back(a%c);
        a/=c;
    }
    while(b>0){
        bb.push_back(b%c);
        b/=c;
    }
    for(int x=0;x<aa.size();x++){
        if(x<bb.size())aa[x]+=bb[x];
        aa[x]%=c;
    }
    while(aa.size()>0 && aa.back()==0){
        aa.pop_back();
    }
    if(aa.size()==0){
        cout<<"0";
    }else{
        while(aa.size()>0){
            cout<<aa.back();
            aa.pop_back();
        }
    }
    return 0;
}