// ans.cpp 26 Dec 17, 15:47:00 100 0.04 Judging completed in 5.472s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
char arr[600005];
int s=300001,e=300001,i;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string a;
    cin>>n;
    while(n--){
        cin>>a;
        if(a=="ADD_FRONT"){
            s--;
            cin>>arr[s];
        }else if(a=="ADD_BACK"){
            cin>>arr[e];
            e++;
        }else if(a=="SNIP_FRONT"){
            cin>>i;
            s+=i;s++;
        }else if(a=="SNIP_BACK"){
            cin>>i;
            e=s+i+1;
        }else if(a=="QUERY"){
            cin>>i;
            cout<<arr[s+i]<<'\n';
        }
    }
    return 0;
}