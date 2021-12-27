// ans.cpp 31 May 17, 15:49:38 0 0 Judging completed in 3.243s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<int> fibo={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733};
bool fibotest(int x){
    int lo,hi,mid;
    lo=0;
    hi=fibo.size()-1;
    while(lo<hi){
        mid=lo+((hi-lo)/2);
        if(fibo[mid]<x){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    if(fibo[lo]==x)return true;
    return false;
}
int main() {
    int n,ans=0;
    cin>>n;
    while(!fibotest(n)){
        ans++;
        if(n%2==0){
            n/=2;
        }else{
            n*=3;
            n+=1;
        }
    }
    return 0;
}