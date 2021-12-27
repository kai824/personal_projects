// ans.cpp 1 Jan 19, 21:15:12 0 1 Judging completed in 6.885s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x,i=0;
    ofstream f;
    while(cin>>x){
        f.open(to_string(i)+".txt");
        f<<x;
        f.close();
        i++;
    }
    ifstream f1;
    while(i--){
        f1.open(to_string(i)+".txt");
        f1.tie(0);
        f1>>x;
        cout<<x<<'\n';
        f1.close();
    }
    return 0;
}