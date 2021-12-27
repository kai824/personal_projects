// ans.cpp 2 Jan 19, 07:59:04 0 0.31 Judging completed in 6.784s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {

    int siz=0,k;
    ofstream out("test.txt");
    while(cin>>k){
        out<<k<<'\n';
        siz++;
    }
    out.close();
    
system	("tac test.txt");

    system("rm test.txt");
    return 0;
}