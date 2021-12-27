// ans.cpp 23 Nov 16, 16:11:23 0 1 Judging completed in 8.015s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int v_min(vector<int> a,int b,int e){//returns the b<=iterator<=e
    int ans=a[b];
    for(int c=b;c<=e;c++){
        if(a[c]<a[ans]) ans=c;
    }
    return ans;
}
int main() {
    pair<int,int> collector;
    vector<int> pebbles;
    int n,k,c,e=0;
    cin>>n>>k;
    for(int d=0;d<n;d++){
        cin>>c;
        pebbles.push_back(c);
    }
    //c is now used as max, which will be the answer
    //e is the iterator of the last one, not neccesarily the max
    e=v_min(pebbles,0,k-1);
    c=0;
    while(n-e>k){
        if(pebbles[e]>c) c=pebbles[e];
        e=v_min(pebbles,e+1,e+k);
    }
    if(pebbles[e]>c) c=pebbles[e];
    cout<<c;
    return 0;
}