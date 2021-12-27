// ans.cpp 5 Dec 17, 11:56:22 100 0 Judging completed in 4.226s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;string a,out;
    cin>>t;
    while(t--){
        cin>>a;
        for(int x=0;x<a.length();x++){
            out=arr[a[x]-'0'];
            if(x==0)out[0]=toupper(out[0]);
            cout<<out;
            if(x+1<a.length())cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}