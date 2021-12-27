// ans.cpp 7 Feb 17, 13:28:11 30 0.44 Judging completed in 6.167s on AWS Ireland.
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
    sort(a,a+n,cmp);
    for(int x=0;x<n;x++){
      cout<<a[x]<<endl;
    }
    return 0;
}