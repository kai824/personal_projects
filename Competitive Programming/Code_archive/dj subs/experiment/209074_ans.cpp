// ans.cpp 2 Jun 17, 21:57:05 100 0.06 Judging completed in 4.501s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,f,l;
    cin>>n;
    double a[n],sum=0,ans;
    for(int x=0;x<n;x++){
        cin>>a[x];
        sum+=a[x];
    }
    sum/=n;
    sort(a,a+n);
    f=n;
    l=-1;
    for(int x=0;x<n;x++){
        if(a[x]>=sum*0.9)f=min(f,x);
        if(a[x]<=sum*1.1)l=max(l,x);
    }
    #include<iomanip>
    cout<<fixed<<setprecision(2);
    if((f+l)%2==0){
        ans=a[(f+l)/2];
    }else{
        ans=(a[(f+l)/2]+a[((f+l)/2)+1])/2;
    }
    ans*=100.0;
    if(ans-floor(ans)>=0.5)ans+=0.5;
    cout<<ans/100.0<<'\n';
    return 0;
}