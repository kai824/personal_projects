// ans.cpp 15 Feb 17, 20:36:58 0 0.03 Judging completed in 6.335s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
struct connection{
    bool a[4]={0,0,0,0};//describing previous experiences.
};
long long int n;
pair<long long int,connection> adjmatrix[105][105],f;//adjmatrix shall be 1-indexed
int main() {
	f.first=pow(INT_MAX,2)/2;
	for(int x=0;x<105;x++){
		for(int y=0;y<105;y++){
			adjmatrix[x][y]=f;
		}
	}
    map<string,int>e;
    e["ground"]=0;
    e["water"]=1;
    e["grass"]=2;
    e["forest"]=3;
    string a;
    long long int m,q,t[4],b,c,d;
    cin>>n>>m>>q>>t[0]>>t[1]>>t[2]>>t[3];
    for(int x=0;x<m;x++){
    	cin>>b>>c>>d>>a;
    	adjmatrix[b][c].first=d+t[e[a]];
    	adjmatrix[b][c].second.a[e[a]]=true;
    	adjmatrix[c][b]=adjmatrix[b][c];
    }
    //we can now reuse b,c,d...
    for(int x=1;x<=n;x++){
    	for(int y=1;y<=n;y++){
    		for(int z=1;z<=n;z++){
    			//adjmatrix[y][z]=min(adjmatrix[y][z],adjmatrix[y][x]+adjmatrix[x][y]);
    			f.first=adjmatrix[y][x].first+adjmatrix[x][z].first;
    			for(int aa=0;aa<4;aa++){
    				if(adjmatrix[y][x].second.a[aa] && adjmatrix[x][z].second.a[aa])f.first-=t[aa];
    				f.second.a[aa]=(adjmatrix[y][x].second.a[aa] || adjmatrix[x][z].second.a[aa]);
    			}if(f.first<adjmatrix[y][z].first)adjmatrix[y][z]=f;
    		}
    	}
    }
    for(int x=0;x<q;x++){
    	cin>>b>>c;
    	if(adjmatrix[b][c].first==pow(INT_MAX,2)/2)cout<<-1<<endl;
    	else cout<<adjmatrix[b][c].first<<endl;
    }
    return 0;
}