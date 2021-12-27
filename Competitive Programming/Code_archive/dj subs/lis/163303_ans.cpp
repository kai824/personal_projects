// ans.cpp 19 Nov 16, 11:08:59 20 0 Judging completed in 4.214s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n,a,max=0,lis=0;
    vector<long long int> history,d;
    cin>>n;
    for(long long int b=0;b<n;b++){
        cin>>a;
        if(b==0){
            lis=1;
            d.push_back(a);
            history.push_back(a);
        }else{
            for(long long int c=history.size()-1;c>=0;c--){
                if(a>d[c]){
                    lis=lis+1;
                    d.push_back(a);
                    history.push_back(a);
                    break;
                }else{
                    lis=lis-1;
                    d.pop_back();
                    history.pop_back();
                    if(c==0){
                      lis=1;
                      d.push_back(a);
                      history.push_back(a);
                    }
                }
            }
        }
        if(lis>max) max=lis;
    }
    cout<<max;
    return 0;
}