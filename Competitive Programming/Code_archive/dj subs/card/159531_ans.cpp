// ans.cpp 5 Nov 16, 14:50:15 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,f,g;
    cin>>a>>b;
    string c;
    deque<int> e;
    cin>>c;
    for(int d=0;d<strlen(c);d=d+1){
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