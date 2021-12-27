// ans.cpp 23 May 17, 16:31:04 100 0.04 Judging completed in 4.881s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    int n,l,a;
    cin>>n>>l;
    string words;
    int scores[n];
    for(int x=0;x<n;x++){
        cin>>words;
        scores[x]=0;
        for(int y=0;y<words.length();y++){
            a=toupper(words[y])-'A';
            scores[x]+=a+1;
        }
    }
    sort(scores,scores+n,cmp);
    a=0;//now used as ans...
    for(int x=0;x<l;x++){
        a+=scores[x];
    }
    cout<<a;
    return 0;
}