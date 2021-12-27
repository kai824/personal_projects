// ans.cpp 23 Nov 16, 18:22:41 40 0 Judging completed in 4.175s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
  int f=0;
    string a,b;
    char last;
    cin>>a;
    cin>>b;
    int e[a.length()][b.length()];
    for(int c=0;c<a.length();c++){
        for(int d=0;d<b.length();d++){
            f=0;
            if(c==0 || (d!=0 && e[c][d-1]>e[c-1][d]))e[c][d]=e[c][d-1];
            else if(c!=0)e[c][d]=e[c-1][d];
            else e[c][d]=0;
            if(a[c]==last) f++;
            if(b[c]==last) f++;
            if(a[c]==b[d] && f!=1){
              e[c][d]+=1;
              last=a[c];
            }if(e[c][d]>min(c,d)+1)e[c][d]=min(c,d)+1;
        }
    }
    cout<<e[a.length()-1][b.length()-1];
    return 0;
}