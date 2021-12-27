// ans.cpp 17 Oct 17, 22:08:40 0 0.13 Judging completed in 7.345s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,ft[200005],a,c;
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
bool cmp(pair<int,int> a,pair<int,int> b){
    return(a.second<b.second);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    pair<int,int> data[n],compress[n];
    for(int x=0;x<n;x++){
        cin>>data[x].first;
        compress[x].first=data[x].first;
        compress[x].second=x;
    }
    
    sort(compress,compress+n);//compressing values
    for(int x=0;x<n;x++){
        if(x==0||compress[x].first!=compress[x-1].first)a++;
        data[compress[x].second].first=a;
    }
    
    for(int x=0;x<n;x++){
        cin>>data[x].second;
    }
    a=0;//now used as ans...
    c=-1;//counting the number of consecutive stuff...
    sort(data,data+n,cmp);
    for(int x=0;x<n;x++){
        update(data[x].first,1);
        if(x==0 || data[x].second==data[x-1].second){
        	c++;
        }else{
        	c=0;
        }
        a+=query(data[x].first-1);
        a-=c;
        //cout<<data[x].first<<' '<<data[x].second<<'\n';
    }
    cout<<a;
    return 0;
}