// ans.cpp 17 Oct 17, 15:39:30 100 0.31 Judging completed in 4.618s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n;
    vector<int> v,vv;
    for(int x=0;x<n;x++){
        v.clear();
        cin>>a;
        for(int y=0;y<a;y++){
            cin>>b;
            v.push_back(b);
            vv.push_back(b);
        }
        sort(v.begin(),v.end());
        b=0;
        for(int y=0;y<v.size();y++){
            if(y==0 || v[y]!=v[y-1]){
                b++;
            }
        }
        cout<<b<<'\n';
    }
    b=0;
    sort(vv.begin(),vv.end());
    for(int x=0;x<vv.size();x++){
        if(x==0||vv[x]!=vv[x-1]){
            b++;
        }
    }
    cout<<b;
    return 0;
}