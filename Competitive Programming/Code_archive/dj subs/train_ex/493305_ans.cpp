// ans.cpp 18 Feb 19, 22:22:43 0 0.04 Judging completed in 4.667s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
set<pair<double,pii> >lines;
set<pair<double,pii> >::iterator it,it2,it3;
//(x-a)^2+h each stores x-coord of intersect with prev,a,h
double dd(double a,int b){//double divide
	double c=a,d=b;
	return(c/d);
}
void add_line(int a,int h){//more like curve
	it=lines.lower_bound(make_pair(a,make_pair(0,0)));
	if(it==lines.end()){//no next line to update
		lines.insert(make_pair(a,make_pair(a,h)));
	}else{
		double i1,i2;
		pair<double,pii> renew_item;
		while(true){
			i1=dd( a+it->second.first+dd((h-it->second.second),(a-it->second.first)),2);
			it++;
			if(it==lines.end()){
				it--;
				break;
			}
			//if(a==3 && h==5)cout<<i1<<' '<<it->first<<'\n';
			if(i1>=it->first){
				it2=it;
				it2--;
				lines.erase(it2);
			}else{
				it--;break;
			}
		}
		//it should now be lower_bound(a,0,0)
		//it=lines.upper_bound(make_pair(a,make_pair(0,0)));it--;
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
	//cout<<'\n';
	for(int x=0;x<n;x++){
		dist[arr[x].second]=query(arr[x].second);
		add_line(arr[x].second,dist[arr[x].second]);//a, h(constant)
		/*cout<<'\n';
		it3=lines.begin();
		while(it3!=lines.end()){
			cout<<it3->first<<' '<<it3->second.first<<' '<<it3->second.second<<'\n';
			it3++;
		}
		cout<<'\n';*/
	}
	cout<<query(n+1);
	return 0;
}