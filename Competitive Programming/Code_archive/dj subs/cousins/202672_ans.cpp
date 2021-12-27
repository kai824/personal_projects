// ans.cpp 29 Mar 17, 20:15:09 0 0.36 Judging completed in 6.629s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> strings;
    string a,prev="LUOL";
    int n;
    cin>>n;
    cin.ignore();
    for(int x=0;x<n;x++){
        getline(cin,a);
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
            prev="LUOL";
        }
    }
    cout<<n;
    return 0;
}