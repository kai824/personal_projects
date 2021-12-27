// ans.cpp 5 Aug 17, 21:55:52 100 0.02 Judging completed in 6.875s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n;
void process(int left,int current){
    if(left==0){
        int legit=current;
        bool arr[n+1];
        for(int x=0;x<n+1;x++)arr[x]=false;
        for(int x=0;x<n;x++){
            if(arr[current%10])return;
            arr[current%10]=true;
            current/=10;
        }
        cout<<legit<<'\n';
        return;
    }
    for(int x=1;x<=n;x++){
        process(left-1,current*10+x);
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    process(n,0);
    return 0;
}