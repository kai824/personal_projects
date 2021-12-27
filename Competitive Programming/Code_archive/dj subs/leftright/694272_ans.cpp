// ans.cpp 3 Feb 20, 22:57:46 100 0.01 Judging completed in 4.455s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q,t,s;
    cin>>q;
    deque<int> d1,d2;
    while(q--){
        cin>>t;
        if(t==1){
            cin>>s;
            d2.push_back(s);
        }else{
            swap(d1,d2);
        }
        while(d1.size()<d2.size()){
            d1.push_back(d2.front());
            d2.pop_front();
        }
    }
    for(int x=0;x<d1.size();x++){
        if(x>0)cout<<' ';
        cout<<d1[x];
    }
    for(int x=0;x<d2.size();x++){
        cout<<' '<<d2[x];
    }
    return 0;
}