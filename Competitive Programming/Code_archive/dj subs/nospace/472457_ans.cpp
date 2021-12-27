// ans.cpp 1 Jan 19, 20:41:14 0 1 Judging completed in 3.643s on AWS Oregon.
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
    
	
    for(int x=0;x<siz;x++){
        ifstream inp("test.txt");
        for(int y=0;y<siz-x;y++){
            inp>>k;
        }
		//inp.seekg(0,inp.beg);
        cout<<k<<'\n';
        inp.close();
    }
    system("rm test.txt");
    return 0;
}