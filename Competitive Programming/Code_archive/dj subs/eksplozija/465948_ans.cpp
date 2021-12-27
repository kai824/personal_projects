// ans.cpp 26 Dec 18, 16:18:28 56.67 0.03 Judging completed in 13.175s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int f[1000001],b_it=0,start=0,p=0;//stores no. of letters matching b
int ss[1000001];//static sum
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int x=0;x<a.length();x++){
        if(a[x]==b[b_it]){
            b_it++;
        }else{
			b_it=0;
			if(a[x]==b[b_it]){
				start=x;
				b_it=1;
			}else{
				b_it=0;
				start=x+1;//start, character in the expl string
			}
        }
        f[x]=b_it;
        if(b_it==b.length()){//found match
            ss[start]++;ss[x+1]--;//mark it out
            if(start==0 || f[start-1]==0){
                start=x+1;
                b_it=0;
            }else{
                b_it=f[start-1];
                start=start-f[start-1];
            }
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