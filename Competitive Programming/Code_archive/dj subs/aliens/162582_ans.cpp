// ans.cpp 15 Nov 16, 22:16:08 0 1.1 Judging completed in 11.131s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> output;
    map<string,int> m;
    int a,d,e,pe,f;
    string c,pc;
    cin>>a;
    for(int b=0;b<a;b++){
        cin>>c>>d;
        if(d==2) output.push_back(m.find(c)->second);
        else{
            cin>>e;
            f=0;
            if(((e==pe)&&(c==pc))||(b==0)){
                if(m.count(c)>0){
                    f=m.find(c)->second;
                    m.erase(m.find(c));
                }
                m[c]=f+1;
            }
            pe=e;
            pc=c;
        }
    }
    for(int b=0;b<output.size();b=b+1){
        cout<<output[b]<<'\n';
    }
    return 0;
}