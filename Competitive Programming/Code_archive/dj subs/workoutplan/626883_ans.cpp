// ans.cpp 4 Dec 19, 10:33:42 0 0.02 Judging completed in 4.19s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,k,a;
    long long spent=0;
    cin>>n>>k;
    long long arr[n],cc[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];//the weight to lift...
    }
    cin>>a;
    for(int x=0;x<n;x++){
        cin>>cc[x];
    }
    priority_queue<int> pq;//stores cost of an energy drink...
    for(int x=0;x<n;x++){
        pq.push(cc[x]);
        while(k<arr[x]){
            k+=a;
            if(pq.empty()){
                cout<<-1;
                return 0;
            }
            spent+=pq.top();
            pq.pop();
        }
    }
    cout<<spent;
    return 0;
}