// ans.cpp 29 Apr 17, 21:18:34 100 0.03 Judging completed in 5.348s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,males=0,females=0;
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a=="MEOW")females++;
        else if(a=="MEW")males++;
    }
    if(males==0)cout<<"OMG MEEEAHHHH!!!!";
    else cout<<females/males;
    return 0;
}