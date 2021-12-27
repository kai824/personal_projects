// ans.cpp 4 May 19, 21:12:24 100 0.46 Judging completed in 4.892s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,k,i,ii,x,y,sum=0,size=0,m=0;
    priority_queue<long long,vector<long long>,greater<long long> >pq;
    cin>>n>>k;
    for (i=0;i<n;i++){
        cin>>x;
        pq.push(x);
        sum+=x;
        size++;
        while (size>k){
            size--;
            sum-=pq.top();
            pq.pop();
        }
        k--;
        m=max(m,sum);
        if (k<=0){
            break;
        }
    
    }
    cout<<m<<endl;
}