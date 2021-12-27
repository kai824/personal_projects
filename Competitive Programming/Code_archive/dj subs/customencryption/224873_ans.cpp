// ans.cpp 20 Oct 17, 13:44:16 40 0.06 Judging completed in 5.171s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    bool b=false;
    int cur=0;
    cin>>a;
    a=a+" ";
    vector<pair<int,int> > v;
    for(int x=0;x<a.length();x++){
        if(isdigit(a[x])==false && cur>0){
            v[v.size()-1].second=cur;
            cur=0;
        }
        
        if(isalpha(a[x])){
            v.push_back(make_pair(((int)(a[x]))-96,1));
        }else if(isdigit(a[x])){
            cur*=10;
            cur+=(a[x]-'0');
        }else if(a[x]=='!'){
            v.push_back(make_pair(-1,-1));
        }
    }
    cur=0;//now used as ans...
    for(int x=v.size()-1;x>=0;x--){
        if(v[x].first==-1 && v[x].second==-1){
            b=!b;
            continue;
        }
        if(b){
            v[x].first+=13;
            if(v[x].first>26)v[x].first-=26;
        }
        
        cur+=v[x].first*v[x].second;
    }
    cout<<cur;
    return 0;
}