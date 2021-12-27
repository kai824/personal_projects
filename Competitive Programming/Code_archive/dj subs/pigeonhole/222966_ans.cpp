// ans.cpp 17 Oct 17, 10:23:05 0 1 Judging completed in 5.188s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<int> get_out(vector<int> f, int e){
    for(int a=0;a<f.size();a=a+1){
        if(f[a]==e) f.erase (f.begin()+a);
    }
    return f;
}
int main() {
    int a,b,d,e,h;
    cin>>a>>b;
    vector<vector<int> > f;
    vector<int> ff;
    for(int c=0;c<b;c++){
        f.push_back(ff);
    }
    for(int c=0;c<a;c++){
        cin>>d>>e;
        if(d==1){
            f[e%b].push_back(e);
        }else if(d==0){
            for(int g=0;g<b;g=g+1){
                f[g]=get_out(f[g],e);
            }
        }
        h=0;
        for(int g=0;g<b;g=g+1){
            if(f[g].size()>h)h=f[g].size();
        }
        ff.push_back(h);
    }
    for(int c=0;c<a;c++){
        cout<<ff[c]<<"\n";
    }
    return 0;
}