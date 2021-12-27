// ans.cpp 26 Jun 17, 15:00:57 100 0 Judging completed in 28.285s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,c=0;
    cin>>a>>b;
    if(a>b)swap(a,b);//ensure a<b
    if(b-a<a){
        c=b-a;
        a-=c;
        b=a;
    }else{
        cout<<a;
        return 0;
    }
    c+=2*(a/3);
    if((a%3)==2)c++;
    cout<<c;
    return 0;
}