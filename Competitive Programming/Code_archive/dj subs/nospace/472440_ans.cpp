// ans.cpp 1 Jan 19, 20:36:35 0 1 Judging completed in 3.58s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

    short int siz,k;
    ofstream out("tmp.txt");
    while(cin>>k){
        out<<k<<'\n';
        siz++;
    }
    out.close();
    
	ifstream inp("tmp.txt");
//	inp.tie(0);
    for(int x=0;x<siz;x++){
        for(int y=0;y<siz-x;y++){
            inp>>k;
        }
		inp.seekg(0,inp.beg);
        cout<<k<<'\n';
    }
	inp.close();
    system("rm tmp.txt");
    return 0;
}