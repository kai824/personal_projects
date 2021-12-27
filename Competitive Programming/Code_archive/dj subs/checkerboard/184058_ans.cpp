// ans.cpp 22 Jan 17, 19:10:04 100 0 Judging completed in 3.829s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if((x+y)%2==0){
                cout<<'o';
            }else{
                cout<<'x';
            }
        }
        cout<<endl;
    }
    return 0;
}