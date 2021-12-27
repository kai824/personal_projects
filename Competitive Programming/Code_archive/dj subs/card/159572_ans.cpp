// ans.cpp 5 Nov 16, 15:09:51 0 0 Judging completed in 4.072s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,f,g,h;
    cin>>a>>b;
    char c[1000000];
    deque<int> e;
    cin>>c;
    for(int d=0;d<1000000;d=d+1){
        if(c[d]!='.') h=h+1;
        else break;
    }
    for(int d=0;d<h;d=d+1){
        e.push_back(d);
    }
    for(int d=0;d<h;d=d+1){
        if(c[d]=='A'){
            f=e[0];
            e.pop_front();
            e.push_back(f);
        }else if(c[d]=='B'){
            f=e[0];
            g=e[1];
            e.pop_front();
            e.pop_front();
            e.push_front(f);
            e.push_back(g);
        }
    }
    cout<<e[b-1]<<" "<<e[b]<<" "<<e[b+1];
    return 0;
}