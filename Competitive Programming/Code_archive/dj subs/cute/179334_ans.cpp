// ans.cpp 9 Jan 17, 09:27:50 0 1 Judging completed in 6.78s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool hasEnding (string fullString,string ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
int main() {
    string a,b,c="",ans="-1";
    cin>>a;
    b=a;
    b.erase(0,1);
    b.erase(b.length()-1,1);
    for(int x=0;x<a.length()-1;x++){
        c=c+" ";
        c[c.length()-1]=a[x];
        if(hasEnding(a,c)&&b.find(c)!=string::npos){
            ans=c;
        }
    }
    cout<<ans;
    return 0;
}