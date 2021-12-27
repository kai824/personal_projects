// ans.cpp 15 Aug 19, 21:37:09 66.67 0.03 Judging completed in 3.663s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int f[1000001],b_it=0,start=0,p=0;//stores no. of letters matching b
int ss[1000001];//static sum
int start_it[1000001];
int prevv[1000001],last=-1;//since the last one not marked may not be start...
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int x=0;x<a.length();x++){
        if(a[x]==b[b_it]){
            b_it++;
        }else{
			if(a[x]==b[0]){//since no 2 characters are same, no need to do kmp stuff...
				start=x;
				b_it=1;//next char to search
			}else{
				b_it=0;
				start=x+1;//start, character in the expl string
			}
        }
		prevv[x]=last;
		last=x;
        f[x]=b_it;
		start_it[x]=start;
		/*if(start==x+1){
			start_it[x]=-1;
		}*/ // already fixed, since f[x] will be 0
        if(b_it==b.length()){//found match
            ss[start]++;ss[x+1]--;//mark it out
            if(prevv[start]==-1 || f[prevv[start]]==0){
                start=x+1;
                b_it=0;
				last=-1;
            }else{
                b_it=f[prevv[start]];
                start=start_it[prevv[start]];
				last=prevv[start];
            }
			//in this case, prev[x] won't matter anymore
        }
    }
	bool output=false;
    for(int x=0;x<a.length();x++){
        p+=ss[x];
        if(p==0){
			cout<<a[x];
			output=true;
		}
		//cout<<f[x]<<' ';
    }
	if(output==false)cout<<"FRULA";
    return 0;
}