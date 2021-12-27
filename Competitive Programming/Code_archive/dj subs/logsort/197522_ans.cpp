// ans.cpp 8 Mar 17, 20:19:22 0 0.16 Judging completed in 3.928s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<queue<int> > v;
    queue<int> to_add,t1,t2;
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        to_add.push(b);
        v.push(to_add);
        to_add.pop();
    }
    while(v.size()>1){
    	t1=v.front();
        v.pop();
        t2=v.front();
        v.pop();
        v.push(to_add);
        for(int x=0;(t1.size()+t2.size());x++){
            if(!t1.size()){
                v.back().push(t2.front());
                t2.pop();
            }else if(!t2.size()){
                v.back().push(t1.front());
                t1.pop();
            }else{
                if(t1.front()<t2.front()){
                    v.back().push(t1.front());
                    t1.pop();
                }else{
                    v.back().push(t2.front());
                    t2.pop();
                }
            }
        }
    }
    while(v.front().size()){
        cout<<v.front().front()<<endl;
        v.front().pop();
    }
    return 0;
}