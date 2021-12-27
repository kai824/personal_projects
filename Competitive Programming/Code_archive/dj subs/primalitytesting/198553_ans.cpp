// ans.cpp 11 Mar 17, 23:00:15 100 0 Judging completed in 2.517s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    bool prime;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        cout<<a<<" is a ";
        prime=true;
        for(int y=2;y<a;y++){
            if(a%y==0){
                cout<<"composite number.\n";
                prime=false;
                break;
            }
            if(y*y>a){
                break;
            }
        }
        if(a<2){
        	prime=false;
        	cout<<"composite number.\n";
        }
        if(prime)cout<<"prime number.\n";
    }
    return 0;
}