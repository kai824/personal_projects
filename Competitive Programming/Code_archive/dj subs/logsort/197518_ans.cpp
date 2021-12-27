// ans.cpp 8 Mar 17, 20:03:10 0 0.14 Judging completed in 3.894s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
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