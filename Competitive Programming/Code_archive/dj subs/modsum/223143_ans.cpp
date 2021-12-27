// ans.cpp 17 Oct 17, 21:30:03 100 0.04 Judging completed in 3.107s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,ans;
pair<int,int> arr[1005];
int f(int x){//x=sum of the stuff inside
    x%=5;
    return( ( (x*x*x*x)+2*(x*x) )%5)+1;
}
void brute_force(int it,int b){
    if(it==n){
        ans+=f(b);
        return;
    }
    for(int x=arr[it].first;x<=arr[it].second;x++){
        brute_force(it+1,b+x);
    }
}
int main(){
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x].first>>arr[x].second;
    }
    brute_force(0,0);//it of next item, current sum
    cout<<ans;
    return 0;
}