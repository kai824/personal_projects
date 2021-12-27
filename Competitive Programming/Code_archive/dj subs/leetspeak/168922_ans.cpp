// ans.cpp 10 Dec 16, 15:49:31 100 0 Judging completed in 5.441s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,c="English";
    cin>>a;
    for(int b=0;b<a.size();b=b+1){
        if(isalpha(a[b])) a=a;
        else c="l33t";
    }
    cout<<c;
    return 0;
}