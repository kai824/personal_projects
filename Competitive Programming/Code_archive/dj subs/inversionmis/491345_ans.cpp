// ans.cpp 14 Feb 19, 20:56:22 0 0.02 Judging completed in 3.095s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int n,a,b;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(v.size()==0 || a>v.back()){
            v.push_back(a);
        }else{//a<last value, need to merge stuff...
            b=v.back();
            v.pop_back();
            while(v.size()>0 && a<v.back()){
                v.pop_back();
            }
            v.push_back(b);
        }
    }
    cout<<v.size();
    return 0;
}