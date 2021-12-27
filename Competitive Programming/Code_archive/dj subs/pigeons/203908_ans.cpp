// ans.cpp 9 Apr 17, 21:50:19 100 0.43 Judging completed in 5.387s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,current=0;
    cin>>m>>n;
    string a;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a=="LAND"){
            current++;
        }else if(a=="LEAVE"){
            current--;
        }else if(a=="EVACUATE"){
            current=0;
        }
        if(current>m){
            cout<<"PLAN REJECTED";
            return 0;
        }
    }
    cout<<"PLAN ACCEPTED";
    return 0;
}