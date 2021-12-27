// ans.cpp 8 Feb 17, 19:13:36 100 0 Judging completed in 4.755s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a=0,b=0,h,w;
    string c;
    cin>>h>>w;
    for(int x=0;x<h;x++){
        cin>>c;
        for(int y=0;y<w;y++){
            if(c[y]=='O')a++;
            else if(c[y]=='N')b++;
        }
    }cout<<a<<' '<<b;
    return 0;
}