// ans.cpp 2 Dec 16, 18:02:21 20 1 Judging completed in 5.269s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
string a,b;
int lcs(int i,int j){
    if(i==0 || j==0) return 0;
    if(a[i]==b[j]) return lcs(i-1,j-1)+1;
    else{
        return max(lcs(i-1,j),lcs(i,j-1));
    }
}
int main() {
    cin>>a;
    cin>>b;
    cout<<lcs(a.length(),b.length());
    return 0;
}