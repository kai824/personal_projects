// ans.cpp 15 Mar 19, 22:29:03 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[26];
inline void ds(char a,int b){
    //do stuff
    arr[a-'a']=b;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s="",t;
    ds('o',100);
    ds('e',10);
    ds('g',1);
    ds('a',0);
    ds('b',-1);
    ds('i',-10);
    ds('u',-100);
    while(cin>>t){
        s+=t;
        if(t[t.length()-1]=='.')break;
    }
    int curmax=0,cursum=0;
    for(int x=0;x<s.length();x++){
        if(x[s]==','){
            cout<<curmax<<'\n';
            curmax=cursum=0;
        }else if(x[s]=='.')break;
        else if(isalpha(x[s])){
            cursum+=arr[x[s]-'a'];
            if(cursum<0)cursum=0;
            curmax=max(curmax,cursum);
        }
    }
    return 0;
}