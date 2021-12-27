// ans.cpp 29 Mar 17, 20:09:30 0 0.4 Judging completed in 5.993s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> strings;
    string a,prev="luol";
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        sort(a.begin(),a.end());
        strings.push_back(a);
    }
    n=0;//now used as ans...
    sort(strings.begin(),strings.end());
    for(int x=0;x<strings.size();x++){
        if(strings[x]!=prev){
            n++;
            prev=strings[x];
        }else{
            prev="luol";
        }
    }
    cout<<n;
    return 0;
}