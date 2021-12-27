// ans.cpp 24 Jan 20, 16:45:18 0 0 Judging completed in 3.458s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s1,s2;s1=s2=0;
    char c;
    cin>>n;
    for(int x=0;x<n;x++){
        c=tolower(getchar_unlocked());
        if((x%2)==0)s1+=1+c-'a';
        else s2+=1+c-'a';
    }
    if((n%2)==1)swap(s1,s2);
    cout<<s1<<' '<<s2;
    return 0;
}