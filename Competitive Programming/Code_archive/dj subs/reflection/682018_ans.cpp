// ans.cpp 18 Jan 20, 16:57:34 14.4 0.04 Judging completed in 6.143s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

struct pt{
	pair<int,int> points[3];
	
	void in(){
		for(int i=0;i<3;i++)cin>>points[i].first>>points[i].second;
	}
	
	bool operator<(const pt& arg) const {
		for(int i=0;i<3;i++){
			if(arg.points[i]!=points[i]){
				return arg.points[i]<points[i];
			}
		}
		return false;
    }
};

bool equal(pt v1,pt v2){
	for(int i=0;i<3;i++){
		if(v1.points[i]!=v2.points[i])return false;
	}
	return true;
}

map<pt,pair<string, pt> > mp;//reflection made, previous point...

void trace(pt point){
	if(mp[point].first=="gay"){
		return;
	}
	trace(mp[point].second);
	cout<<mp[point].first<<'\n';
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);
	int t;
	string s;
	cin>>t;
	
	pt pt1,pt2,pt3;
	pt1.in();
	pt2.in();
	
	queue<pair<int,pt> > bfs;//distance, cords...
	bfs.push(make_pair(0,pt1));
	mp[pt1]=make_pair("gay",pt3);
	while(!equal(bfs.front().second,pt2)){
		if(bfs.front().first>7){
			cout<<"-1";
			return 0;
		}
		for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){//reflect ith point about jth point...
				if(i==j)continue;
				pt3=bfs.front().second;
				pt3.points[i].first-=2*(pt3.points[i].first-pt3.points[j].first);
				pt3.points[i].second-=2*(pt3.points[i].second-pt3.points[j].second);
				
				if(mp.find(pt3)==mp.end()){
					s="ab";
					s[0]='A'+i;
					s[1]='A'+j;
					mp[pt3]=make_pair(s,bfs.front().second);
					bfs.push(make_pair(bfs.front().first+1,pt3));
				}
				
				if(equal(pt3,pt2)){
					cout<<bfs.front().first+1<<'\n';
					trace(pt2);
					return 0;
				}
			}
		}
		bfs.pop();
	}
	return 0;
}