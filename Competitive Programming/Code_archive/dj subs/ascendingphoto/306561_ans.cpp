// ans.cpp 26 Dec 17, 15:33:36 0 0.11 Judging completed in 5.045s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool taken[1000005],c;
int cnts[1000005];
//marks whether the intersection between section x and section x+1 is taken
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,current_it=0,sections=0,continuous;
    cin>>n;
    int arr[n];
    pair<int,int> a[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        a[x].second=x;
        a[x].first=arr[x];
    }
    sort(a,a+n);
    arr[a[0].second]=0;
    for(int x=1;x<n;x++){
        if(a[x].first!=a[x-1].first){
            current_it++;
        }
        arr[a[x].second]=current_it;
        cnts[current_it]++;
    }
    continuous=1;
    for(int x=1;x<n;x++){
        if(arr[x]!=arr[x-1]){
            if(arr[x]-arr[x-1]==1 && taken[arr[x-1]]==false){
                if(c&&cnts[arr[x-1]]!=continuous){
                	//cout<<x<<' ';
                    sections++;
                    c=false;
                    continuous=1;
                    continue;
                }
                taken[arr[x-1]]=true;
                c=true;
            }else{
                sections++;
                //cout<<x<<' ';
                c=false;
            }
            continuous=1;
        }else{
            continuous++;
        }
    }
    cout<<sections;
    return 0;
}