// ans.cpp 7 Aug 17, 17:53:33 100 0.02 Judging completed in 5.672s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,prev,current,cuts=0;
    char direction='-';
    cin>>n;
    cin>>prev;
    for(int x=1;x<n;x++){
        cin>>current;
        if(direction=='-'){
            if(current>prev){
                direction='u';
            }else if(current<prev){
                direction='d';
            }else{
                cuts++;
            }
        }else if(direction=='d'){
            if(current>=prev){
                cuts++;
                direction='-';
            }
        }else if(direction=='u'){
            if(current<=prev){
                cuts++;
                direction='-';
            }
        }
        prev=current;
    }
    cout<<cuts;
    return 0;
}