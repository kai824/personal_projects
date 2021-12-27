// scrivener.cpp 18 Jan 18, 09:58:43 5 0.67 Judging completed in 6.332s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n=1000000,parent[21][1000005],a,b,depth[1000005],current=0;
bool visited[1000005];
char value[1000005];
vector<int>adjlis[1000005];
void build(ll x,ll d){//visits parents before children...
    visited[x]=true;
    depth[x]=d;
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            parent[0][adjlis[x][i]]=x;
            build(adjlis[x][i],d+1);
        }
    }
}

void init(){
	for(ll i=1;i<21;i++){
		for(ll j=0;j<n;j++){
			if(parent[i-1][j]==-1){
				parent[i][j]=-1;
				continue;
			}
			parent[i][j]=parent[i-1][parent[i-1][j]];
		}
	}
}

ll query(ll x,ll k,ll next_bit){
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	return query(parent[next_bit][x],k-(1<<next_bit),next_bit-1);
}

void Init(){
    parent[0][0]=-1;
    build(0,0);
    init();
    value[0]=-1;
    depth[0]=0;
}

void TypeLetter(char l){
    current++;
    parent[0][current]=current-1;
    depth[current]=depth[current-1]+1;
    value[current]=l;
    for(int y=1;y<21;y++){
        if((1<<y)>depth[current]){
            parent[y][current]=-1;
            continue;
        }
        parent[y][current]=query(parent[y-1][current],(1<<(y-1) ) ,19);
    }
}

void UndoCommands(int u){//replicate node current-u
    /*int copy=query(current,u,20);
    depth[current+1]=depth[copy];
    value[current+1]=value[copy];
    for(int y=0;y<21;y++){
        parent[y][current+1]=parent[y][copy];
    }
    current++;*/
}

char GetLetter(int p){
    p++;
    return value[query(current,depth[current]-p,20)];
}