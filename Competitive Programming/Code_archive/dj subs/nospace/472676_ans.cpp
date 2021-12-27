// ans.cpp 2 Jan 19, 08:01:55 0 0.39 Judging completed in 3.631s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {

    int siz=0,k;
    ofstream out("test.txt");
    while(cin>>k){
        if(siz>0)out<<'\n';
        out<<k;
        siz++;
    }
    out.close();
    
system	("tac test.txt");

    system("rm test.txt");
    return 0;
}