// ans.cpp 11 Feb 17, 14:25:45 0 4.01 Judging completed in 10.061s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int a[2600][2600];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string aa;
    int r,w,q,k,b,c,d,e,f;
    cin>>r>>w>>k>>q;
    for(int x=0;x<q;x++){
        cin>>aa>>b>>c>>d;
        if(aa=="feed"){
            a[b-1][c-1]=(a[b-1][c-1]+d)%k;
        }else{
            cin>>e;
            f=0;
            for(int y=b-1;y<d;y++){
                for(int z=c-1;z<e;z++){
                    if((z+y)%2==0){
                        if(a[y][z]%2==0){
                            f++;
                            if(a[y][z]+1==k && k%2==1)f++;
                        }
                    }else{
                        if(a[y][z]%2==1){
                            f++;
                        }
                    }
                }
            }
            cout<<min(f,(d-b+1)*(e-c+1)-f)<<endl;
        }
    }
    return 0;
}