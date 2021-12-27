// ans.cpp 1 Jan 19, 20:39:05 0 0.04 Judging completed in 2.701s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {

    short int siz=0,k;
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