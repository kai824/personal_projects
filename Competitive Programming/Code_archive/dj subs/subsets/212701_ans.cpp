// ans.cpp 26 Jun 17, 15:20:40 20 0.12 Judging completed in 6.711s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,trees[25];
//it as in iterator of next one to add, cur as in current sum
void process(int it,ll cur){
    if(it==n){
        cout<<cur<<'\n';
        return;
    }
    process(it+1,cur);
    process(it+1,cur+trees[it]);
}
bool cmp(int a,int b){
	return(a>b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>trees[x];
    }
    sort(trees,trees+n,cmp);
    process(0,0);
    return 0;
}