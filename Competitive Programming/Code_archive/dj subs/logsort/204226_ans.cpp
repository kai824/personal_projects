// ans.cpp 15 Apr 17, 21:04:04 100 0.11 Judging completed in 4.51s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    deque<vector<int> > v;
    vector<int> to_add;
    int a,b,p1,p2;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        to_add.push_back(b);
        v.push_back(to_add);
        to_add.pop_back();
    }
    while(v.size()>1){
        v.push_back(to_add);
        p1=0;
        p2=0;
        while(p1+p2<v[0].size()+v[1].size()){
            if(p1>=v[0].size()){
                v[v.size()-1].push_back(v[1][p2]);
                //v[1].pop_front();
                p2++;
            }else if(p2>=v[1].size()){
                v[v.size()-1].push_back(v[0][p1]);
                //v[0].pop_front();
                p1++;
            }else{
                if(v[0][p1]<v[1][p2]){
                    v[v.size()-1].push_back(v[0][p1]);
                    //v[0].pop_front();
                    p1++;
                }else{
                    v[v.size()-1].push_back(v[1][p2]);
                    //v[1].pop_front();
                    p2++;
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