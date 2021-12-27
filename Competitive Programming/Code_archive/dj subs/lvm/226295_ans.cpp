// ans.cpp 21 Oct 17, 14:29:18 100 0 Judging completed in 3.448s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,b,reg;
string a;
vector<int> lvm;
vector<pair<string,vector<int> > > instructions;
pair<string,vector<int> > to_push;
vector<int> ifzeros;
int main() {
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        to_push.first=a;
        to_push.second.clear();
        if(a=="PUSH"){
            cin>>b;
            to_push.second.push_back(b);
        }else if(a=="IFZERO"){
            cin>>b;
            to_push.second.push_back(b);
        }
        instructions.push_back(to_push);
    }
    for(int x=0;x<instructions.size();x++){
        if(instructions[x].first=="IFZERO"){
        	b=lvm.back();
        	lvm.pop_back();
        	if(b!=0)continue;
            else{
            	x=instructions[x].second[0];
            }
        }
        a=instructions[x].first;
        if(a=="PUSH"){
            lvm.push_back(instructions[x].second[0]);
        }else if(a=="STORE"){
            reg=lvm.back();
            lvm.pop_back();
        }else if(a=="LOAD"){
            lvm.push_back(reg);
        }else if(a=="PLUS"){
            b=lvm.back();
            lvm.pop_back();
            lvm[lvm.size()-1]+=b;
        }else if(a=="TIMES"){
            b=lvm.back();
            lvm.pop_back();
            lvm[lvm.size()-1]*=b;
        }else if(a=="DONE"){
            cout<<lvm.back();
            break;
        }
    }
    return 0;
}