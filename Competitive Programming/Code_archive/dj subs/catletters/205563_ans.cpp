// ans.cpp 30 Apr 17, 20:53:30 100 0.03 Judging completed in 4.955s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,c=0,d=0;
    cin>>a;
    string b;
    for(int x=0;x<a;x++){
        cin>>b;
        d+=b.length();
        for(int y=0;y<b.length();y++){
            if(toupper(b[y])=='C'){
                c++;
            }
        }
    }
    cout<<(c*100)/d<<"%";
    return 0;
}