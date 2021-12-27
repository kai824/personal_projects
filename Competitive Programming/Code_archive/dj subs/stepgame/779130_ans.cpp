// ans.cpp 9 Nov 20, 10:47:31 100 0.07 Judging completed in 3.417s on AWS Oregon.
//Kadane's algorithm
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,min_num=INT_MAX; cin>>n;
    int array[n]; int current=0;
    for (int i=0; i<n; i++) {
        cin>>array[i];
        min_num=min(min_num,array[i]);
    }
    int minimum=0;
    for (int i=0; i<n; i++) {
        current+=array[i];
        if (current>0) current=0;
        else minimum=min(minimum,current);
    }
    if(minimum==0)cout<<min_num;
    else cout<<minimum;
    return 0;
}