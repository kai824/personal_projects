// ans.cpp 9 Nov 16, 19:00:22 100 0 Judging completed in 9.327s on AWS Ireland.
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