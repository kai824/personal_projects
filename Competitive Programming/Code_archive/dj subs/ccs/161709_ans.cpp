// ans.cpp 12 Nov 16, 15:07:14 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<bool> a;//true is asleep, false is awake.
    vector<string> output;//true is YES, false is NO
    long long int b,c,e,h;
    string d;
    cin>>b>>c;
    string g;
    bool j=false;
    for(int f=0;f<b;f=f+1){
        a.push_back(j);
    }
    for(int f=0;f<c;f=f+1){
        cin>>d>>e;
        if(d=="WAKE") a[e]=false;
        else if(d=="SLEEP") a[e]=true;
        else if(d=="TRANSMIT"){
            cin>>h;
            g="YES";
            for(int i=e;i<=h;i=i+1){
                if(a[i]) g="NO";
            }
            output.push_back(g);
        }
    }
    copy(output.begin(), output.end(), ostream_iterator<string>(cout, "\n"));
    }
    return 0;
}