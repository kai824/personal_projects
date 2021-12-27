// ans.cpp 26 Jan 19, 20:21:24 68 0.16 Judging completed in 3.847s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ps[151][5001];//take to be 1-indexed, easier to prefix
inline int query(int xx, int yy, int xx2, int yy2){
	return(ps[xx2][yy2]+ps[xx-1][yy-1]-ps[xx2][yy-1]-ps[xx-1][yy2]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,ones=0,linep,max_sum=0,cur_sum;
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        linep=0;
        for(int y=1;y<=m;y++){
            cin>>a;
            if(a==1)ones++;
            linep+=a;
            ps[x][y]=ps[x-1][y]+linep;
        }
    }
    //max_sum will be no. of ones in rect - no. of 0s in rect
    for(int x=1;x<=n;x++){
        for(int y=x;y<=n;y++){
            cur_sum=0;
            for(int i=1;i<=m;i++){
                cur_sum+=2*query(x,i,y,i)-(y-x+1);
                if(cur_sum<0)cur_sum=0;
                max_sum=max(max_sum,cur_sum);
            }
        }
    }
    cout<<ones-max_sum;
    return 0;
}
//total cost= ones - (no. of ones in rect - no. of 0s in rect)
//therefore, maximise no. of ones in rect - no. of 0s in rect