// ans.cpp 29 Oct 17, 17:34:56 46 0.02 Judging completed in 3.889s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,mini=INT_MAX,current;
    cin>>n>>k;
    k=min(k,n);
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int> > pq2;
    //trying every possible range...
    for(int x=0;x<n;x++){//starting point of the range...
        for(int y=x;y<n;y++){//ending point of range...
            while(!pq1.empty()){pq1.pop();}
            while(!pq2.empty()){pq2.pop();}
            for(int i=0;i<x;i++){//outside the range...
                pq2.push(arr[i]);
            }
            current=0;
            for(int i=x;i<=y;i++){
                current+=arr[i];
                pq1.push(arr[i]);
            }
            for(int i=y+1;i<n;i++){
                pq2.push(arr[i]);
            }
            for(int i=0;i<min(k,min(y-x+1,n-(y-x+1)));i++){
                current-=pq1.top();
                current+=pq2.top();
                pq1.pop();
                pq2.pop();
            }
            mini=min(current,mini);
            
        }
    }
    cout<<mini;
    return 0;
}