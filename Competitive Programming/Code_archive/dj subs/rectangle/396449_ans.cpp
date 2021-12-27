// ans.cpp 10 Oct 18, 17:56:45 0 0.51 Judging completed in 4.53s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,p1,p2,pp1,pp2,pp3;
	long long max_area=0,new_one;
	double diff1,diff2,gradient,len,c,d;
	cin>>n;
	pair<long long,long long> coords[n];
	for(long long x=0;x<n;x++){
		cin>>coords[x].first>>coords[x].second;
	}
	vector<pair<pair<double,pair<double,double> >,pair<short int,short int> > >lines;
	//gradient, length, y-intercept, point1 it, point2 it
	vector<pair<long long,pair<long long,long long> > >vertical;
	//max y-coord, length, x-coord
	for(long long x=0;x<n;x++){
		for(long long y=0;y<n;y++){
			diff1=coords[x].first-coords[y].first;
			diff2=coords[x].second-coords[y].second;
			if(diff1==0){
				vertical.push_back( make_pair(max(coords[x].second,coords[y].second),make_pair(abs(diff2),coords[x].first ) ) );
				continue;
			}
			gradient=diff2/diff1;
			len=sqrt((diff1*diff1)+(diff2*diff2));
			d=coords[x].first;
			c=coords[x].second-(gradient*d);
			lines.push_back(make_pair( make_pair(gradient,make_pair(len,c)),make_pair(x,y) ));
		}
	}
	sort(lines.begin(),lines.end());
	sort(vertical.begin(),vertical.end());
	p1=0,p2=0;
	for(long long x=0;x+1<vertical.size();x++){
		if(vertical[x].first==vertical[x+1].first && vertical[x].second.first==vertical[x+1].second.first){
			p2=x+1;
			new_one=vertical[x].second.first*(vertical[p2].second.second-vertical[p1].second.second);
			max_area=max(max_area,new_one);
		}else{
			p1=x+1;p2=x+1;
		}
	}
	p1=0,p2=0;
	for(long long x=0;x+1<lines.size();x++){
		if(lines[x].first.first==lines[x+1].first.first && lines[x].first.second.first==lines[x+1].first.second.first){
			p2=x+1;
			pp1=lines[p1].second.first;pp2=lines[p1].second.second;pp3=lines[p2].second.first;//iterator of the points in coords
			new_one=abs((coords[pp1].first*coords[pp2].second)+(coords[pp2].first*coords[pp3].second)+(coords[pp3].first*coords[pp1].second)-(coords[pp2].first*coords[pp1].second)-(coords[pp3].first*coords[pp2].second)-(coords[pp1].first*coords[pp3].second));
			max_area=max(max_area,new_one);
		}else{
			p1=x+1;p2=x+1;
		}
	}
	cout<<max_area;
	return 0;
}