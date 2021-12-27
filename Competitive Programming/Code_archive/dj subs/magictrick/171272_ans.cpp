// ans.cpp 15 Dec 16, 21:47:43 0 0 Judging completed in 4.623s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string ans;
    short int a,b,t,arrangement[4][4],arrangement2[4][4];
    cin>>t;
    for(int x=1;x<=t;x++){
        cin>>a;
        for(int y=0;y<4;y++){
            for(int z=0;z<4;z++){
                cin>>arrangement[y][z];
            }
        }
        cin>>b;
        for(int y=0;y<4;y++){
            for(int z=0;z<4;z++){
                cin>>arrangement2[y][z];
            }
        }
        ans="Volunteer cheated!";
        for(int y=0;y<4;y++){
            for(int z=0;z<4;z++){
                if(arrangement2[b-1][z]==arrangement[a-1][y]){
                    if(ans=="Volunteer cheated!"){
                        ans="a";
                        ans[0]=arrangement2[b-1][z]+'0';
                    }else ans="Bad magician!";
                }
            }
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
    return 0;
}