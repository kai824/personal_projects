// ans.cpp 21 May 17, 12:42:23 50 0 Judging completed in 7.493s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int a[2092501]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733};
int main() {
	int n;
    cin>>n;
    if(n>2092500){
        for(int x=0;1==1;x++){
            if(a[x]==0)break;
            if(n==a[x]){
                cout<<n;
                return 0;
            }
        }
        cout<<1;
        return 0;
    }
    a[0]=-1;
    for(int x=1;x<=n;x++){
        for(int y=1;(true);y++){
            if(y*2<a[x-y]){
                a[x]=y;
                break;
            }
            if(y*3>=x){
                a[x]=x;
                break;
            }
        }
    }
    cout<<a[n];
    return 0;
}