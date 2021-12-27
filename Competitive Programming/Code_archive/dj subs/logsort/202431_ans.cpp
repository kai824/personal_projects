// ans.cpp 28 Mar 17, 08:40:01 0 0.16 Judging completed in 2.482s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<deque<int> > v;
    deque<int> to_add;
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        to_add.push_back(b);
        v.push_back(to_add);
        to_add.pop_back();
    }
    while(v.size()>1){
        v.push_back(to_add);
        for(int x=0;(v[0].size()+v[1].size());x++){
            if(!v[0].size()){
                v[v.size()-1].push_back(v[1][0]);
                v[1].pop_front();
            }else if(!v[1].size()){
                v[v.size()-1].push_back(v[0][0]);
                v[0].pop_front();
            }else{
                if(v[0][0]<v[1][0]){
                    v[v.size()-1].push_back(v[0][0]);
                    v[0].pop_front();
                }else{
                    v[v.size()-1].push_back(v[1][0]);
                    v[1].pop_front();
                }
            }
        }
        v.pop_front();
        v.pop_front();
    }
    for(int x=0;x<v[0].size();x++){
        cout<<v[0][x]<<endl;
    }
    return 0;
}