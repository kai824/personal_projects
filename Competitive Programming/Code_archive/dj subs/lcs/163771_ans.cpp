// ans.cpp 19 Nov 16, 14:57:06 60 0 Judging completed in 3.372s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a;
    cin>>b;
    int e[a.length()][b.length()];
    for(int c=0;c<a.length();c++){
        for(int d=0;d<b.length();d++){
            if(c==0 || (d!=0 && e[c][d-1]>e[c-1][d]))e[c][d]=e[c][d-1];
            else if(c!=0)e[c][d]=e[c-1][d];
            else e[c][d]=0;
            if(a[c]==b[d])e[c][d]+=1;
            if(e[c][d]>min(c,d)+1)e[c][d]=min(c,d)+1;
        }
    }
    cout<<e[a.length()-1][b.length()-1];
    return 0;
}