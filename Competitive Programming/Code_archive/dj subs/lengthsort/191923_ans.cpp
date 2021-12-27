// ans.cpp 15 Feb 17, 21:03:22 30 0.24 Judging completed in 5.583s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    if(a.length()==b.length())return(true);
    else return(a.length()>b.length());
}
int main() {
    int n;
    cin>>n;
    string a[n];
    for(int x=0;x<n;x++){
        cin>>a[x];
    }
    stable_sort(a,a+n,cmp);
    for(int x=0;x<n;x++){
      cout<<a[x]<<endl;
    }
    return 0;
}