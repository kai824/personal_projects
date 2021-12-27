// ans.cpp 8 Feb 17, 19:38:27 0 0 Judging completed in 2.555s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    bool broke;
    int a,b,c=-1,d=-1;//let c be the iterator of the ans, and d be the age of the ans
    cin>>a;
    for(int x=1;x<=a;x++){//not the one I usually do, but for convenience that x will be iterator of number I'm getting
        cin>>b;
        broke=false;
        for(int y=2;y<x;y++){//checking if x is prime
            if(x%y==0){
                broke=true;
                break;
            }
        }
        if(!broke && b>=d){
            d=b;
            c=x;
        }
    }
    cout<<c;
    return 0;
}