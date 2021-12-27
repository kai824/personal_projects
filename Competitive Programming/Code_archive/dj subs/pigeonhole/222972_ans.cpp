// ans.cpp 17 Oct 17, 10:31:58 30 1 Judging completed in 4.869s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2000005];
bool ch[2000005];
int main() {
    int n,h,a,b,c=0;
    cin>>n>>h;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if(a==0)arr[b%h]--;
        else arr[b%h]++;
        if(ch[b%h]!=(arr[b%h]>1)){
        	ch[b%h]=(arr[b%h]>1);
        	if(ch[b%h]==0)c--;
        	else c++;
        }
        cout<<(c>0)<<'\n';
    }
    return 0;
}