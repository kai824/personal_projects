// ans.cpp 28 Oct 17, 12:58:45 100 0.25 Judging completed in 3.222s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,a,lo,hi,mid;
    cin>>n;
    int arr[n+2];
    arr[0]=INT_MIN;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    arr[n+1]=INT_MAX;
	n+=2;
    sort(arr,arr+n);
    cin>>q;
    for(int x=0;x<q;x++){
        cin>>a;
        cout<<"Smaller: ";
        lo=0;
        hi=n-1;
        while(lo<hi){//find iterator of smallest number >= a
            mid=lo+((hi-lo)/2);
            if(arr[mid]>=a)hi=mid;
            else lo=mid+1;
        }if(n!=3){
            cout<<lo-1;
        }else{
            if(arr[1]<a)cout<<1;
            else cout<<0;
        }
        cout<<", Greater: ";
        lo=0;hi=n-1;
        while(lo<hi){//find iterator of largest number <=a
            mid=lo+((hi-lo)/2)+1;
            if(arr[mid]<=a)lo=mid;
            else hi=mid-1;
        }
        if(n!=3){
            cout<<n-lo-2;
        }else{
            if(arr[1]>a)cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}