// ans.cpp 1 Jan 19, 20:56:31 0 1 Judging completed in 3.288s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {

    short int siz=0,k,cnt;
    ofstream out("tmp.txt");
    while(cin>>k){
		if(k==1001)break;
        out<<k<<'\n';
        siz++;
    }
    out.close();
    
	ifstream inp("tmp.txt");
	inp.tie(0);
	/*cout<<"k";
	for(int y=1;y<siz;y++){
		inp>>k;
		cout<<k<<'\n';
		cout<<inp.peek()<<'\n';
	}
	inp.close();
	return 0;*/
	for(int y=1;y<siz;y++){
		inp>>k;
	}
    while(siz--){
        inp>>k;
        cout<<k<<'\n';
		cnt=0;
		if(siz==0)break;
		inp.unget();
		inp.unget();
		while(cnt<1){
			if(inp.peek()=='\n')cnt++;
			inp.unget();
		}
    }
	inp.close();
    system("rm tmp.txt");
    return 0;
}