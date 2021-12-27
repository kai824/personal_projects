// ans.cpp 19 Oct 17, 16:26:07 80 1 Judging completed in 12.838s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct state{
    int s[8];
    int d;//number of swaps...
} start;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int tc,n;
    bool sorted;
    queue<pair<state,int> >bfs;
    cin>>tc;
    while(tc--){
        while(!bfs.empty()){
        	bfs.pop();
        }
        cin>>n;
        for(int x=n-1;x>=0;x--){
            cin>>start.s[x];
        }
        start.d=0;
        bfs.push(make_pair(start,0));
        while(!bfs.empty()){
            sorted=true;
            for(int x=0;x<n-1;x++){
                if(bfs.front().first.s[x]>bfs.front().first.s[x+1]){
                    //not >=
                    sorted=false;
                    break;
                }
            }
            if(sorted){
                cout<<bfs.front().first.d<<'\n';
                break;
            }
            for(int x=n;x>=2;x--){//flip the first x...
                if(x==bfs.front().second)continue;
                start=bfs.front().first;
                //carry out flipping...
                for(int y=0;y<x;y++){
                    if(y>=x-1-y)break;
                    swap(start.s[y],start.s[x-1-y]);
                }
                start.d++;
                bfs.push(make_pair(start,x));
            }
            bfs.pop();
        }
    }
    return 0;
}