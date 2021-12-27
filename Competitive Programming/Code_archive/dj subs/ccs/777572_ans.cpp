// ans.cpp 7 Nov 20, 15:40:53 100 0.14 Judging completed in 4.855s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,b,c;
    string a;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        cin>>a;
        if(a=="TRANSMIT"){
            cin>>b>>c;
            if(s.lower_bound(b)==s.upper_bound(c)){
            	//None involed are asleep
            	cout<<"YES\n";
            }else cout<<"NO\n";
        }else if(a=="SLEEP"){
            cin>>b;
            if(s.find(b)==s.end() || true){
                //check if it is asleep first...
                s.insert(b);
            }
        }else{//a=="WAKE"
            cin>>b;
            //auto it=s.find(b);
            //if(it==s.end())continue;
            s.erase(b);
        }
    }
    return 0;
}