// ans.cpp 7 Feb 17, 13:06:18 100 0 Judging completed in 5.349s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if((a[a.length()-1]-'0')%2==0)cout<<"even\n";
        else cout<<"odd\n";
    }
    return 0;
}