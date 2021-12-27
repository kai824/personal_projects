// ans.cpp 1 Jan 19, 20:38:47 0 1 Judging completed in 3.479s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {

    short int siz,k;
    ofstream out("test.txt");
    while(cin>>k){
        out<<k<<'\n';
        siz++;
    }
    out.close();
    
	ifstream inp("test.txt");
//	inp.tie(0);
    for(int x=0;x<siz;x++){
        for(int y=0;y<siz-x;y++){
            inp>>k;
        }
		inp.seekg(0,inp.beg);
        cout<<k<<'\n';
    }
	inp.close();
    system("rm test.txt");
    return 0;
}