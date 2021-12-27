// ans.cpp 18 Feb 19, 11:05:41 0 0.03 Judging completed in 4.291s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
set<pair<double,pii> >lines;
set<pair<double,pii> >::iterator it,it2;
//(x-a)^2+h each stores x-coord of intersect with prev,a,h
double dd(double a,int b){//double divide
	double c=a,d=b;
	return(c/d);
}
void add_line(int a,int h){//more like curve
	it=lines.upper_bound(make_pair(a,make_pair(0,0)));
	if(it==lines.end()){//no next line to update
		lines.insert(make_pair(a,make_pair(a,h)));
	}else{
		pair<double,pii> renew_item;
		while(true){
			renew_item=make_pair(dd( a+it->second.first+dd((h-it->second.second),(a-it->second.first)),2),it->second);
			it++;
			if(it==lines.end()){
				it--;
				break;
			}
			if(renew_item.first>=it->first){
				it2=it;
				it--;
				lines.erase(it2);
			}
		}
		renew_item=make_pair(dd( a+it->second.first+dd((h-it->second.second),(a-it->second.first)),2),it->second);
		lines.erase(it);
		lines.insert(renew_item);
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
		add_line(arr[x].second,dist[arr[x].second]);//a, h(constant)
	}
	cout<<query(n+1);
	return 0;
}