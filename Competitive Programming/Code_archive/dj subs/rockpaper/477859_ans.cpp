// ans.cpp 15 Jan 19, 22:06:24 0 0 Judging completed in 2.381s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a;
    int score,r=0,p=0;
    cin>>a;
    for(int x=0;x<a.length();x++){
        if(a[x]=='p'){
            if(p>=r){
                score--;
                r++;//forced to play rock
            }else p++;
        }else{
            if(p<r){
                //can play paper
                score++;
                p++;
            }else r++;
        }
    }
    cout<<score;
    return 0;
}