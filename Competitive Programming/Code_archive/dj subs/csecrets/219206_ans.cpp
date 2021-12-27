// ans.cpp 20 Aug 17, 21:28:04 100 0.11 Judging completed in 4.133s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int n,x=0,y=0,z;
    cin>>n;
    z=a.size()/n;
    for(int i=0;i<z;i++){
    	cout<<a.substr(i*n,n);
    	cout<<b.substr(i*n,n);
    }
    return 0;
}