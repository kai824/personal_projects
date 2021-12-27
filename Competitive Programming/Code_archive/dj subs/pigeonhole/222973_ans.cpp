// ans.cpp 17 Oct 17, 10:32:52 100 0.14 Judging completed in 7.096s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2000005];
bool ch[2000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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