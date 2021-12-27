// ans.cpp 17 Feb 19, 18:32:10 0 0.05 Judging completed in 4.379s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
set<pair<int,pii> >lines;
set<pair<int,pii> >::iterator it;
//(x-a)^2+h each stores x-coord of intersect with prev,a,h
int dd(int a,int b){//double divide
	int c=a,d=b;
	return(c/d);
}
void add_line(int a,int h){//more like curve
	it=lines.upper_bound(make_pair(a,make_pair(0,0)));
	if(it==lines.end()){//no next line to update
		lines.insert(make_pair(a,make_pair(a,h)));
	}else{
		lines.insert(make_pair(dd( a+it->second.first+
		dd((h-it->second.second),(a-it->second.first))
		,2.0),it->second));//need to update intersect, since it's now with current line
		lines.erase(it);
		lines.insert(make_pair(a,make_pair(a,h)));
	}
}
int query(int x){//querying min value based on x
	it=lines.upper_bound(make_pair(x,make_pair(0,0)));//find first one larger than x
	it--;
	return((x- it->second.first)*(x- it->second.first)+it->second.second);
}
bool cmp(pii a,pii b){
	if(a.first==b.first){
		return(a.second<b.second);//the earlier one first
	}else return(a.first>b.first);//taller one first
}
int dist[50005];
int main(){
	/*//lines.insert(make_pair(0,make_pair(0,0)));
	//lines.insert(make_pair(1,make_pair(1,1)));
	//lines.insert(make_pair(3,make_pair(3,5)));
	add_line(0,0);
	add_line(1,1);
	add_line(3,5);
	cout<<query(2)<<'\n';
	add_line(2,2);
	it=lines.begin();
	while(it!=lines.end()){
		cout<<it->first<<' '<<it->second.first<<' '<<it->second.second<<'\n';
		it++;
	}
	return 0;*/
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	pii arr[n];
	dist[0]=0;
	for(int x=0;x<n;x++){
		cin>>arr[x].first;
		arr[x].second=x+1;//the a in the line
	}
	lines.insert(make_pair(0,make_pair(0,0)));
	sort(arr,arr+n,cmp);
	for(int x=0;x<n;x++){
		dist[arr[x].second]=query(arr[x].second);
		//since arr[x].second is like the x variable
		add_line(arr[x].second,dist[arr[x].second]);//a, h(constant)
	}
	cout<<query(n+1);
	return 0;
}