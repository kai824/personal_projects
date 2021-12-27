// ans.cpp 1 Jan 19, 20:31:33 0 0 Judging completed in 2.47s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    FILE * f;
    ios::sync_with_stdio(false);
    short int siz,k;
    f=fopen("tmp.txt","wb");
    while(cin>>k){
		if(k==1001)break;
        fprintf(f,"%d\n",k);
        siz++;
    }
    fclose(f);
    
	ifstream inp("tmp.txt");
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