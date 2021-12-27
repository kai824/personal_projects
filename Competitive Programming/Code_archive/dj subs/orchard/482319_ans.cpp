// ans.cpp 26 Jan 19, 20:25:28 100 0.14 Judging completed in 5.402s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,ones=0,linep,max_sum=0,cur_sum;
    cin>>n>>m;
    int ps[n+1][m+1];
    for(int x=0;x<=n;x++){
        for(int y=0;y<=n;y++){
            ps[x][y]=0;
        }
    }
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
                cur_sum+=2*(ps[y][i]+ps[x-1][i-1]-ps[y][i-1]-ps[x-1][i])-(y-x+1);
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