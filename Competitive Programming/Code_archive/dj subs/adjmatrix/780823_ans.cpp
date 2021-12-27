// ans.cpp 11 Nov 20, 09:42:39 100 0 Judging completed in 6.092s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,f,e;
    cin>>a>>b;
    int c[a][a];
    for(int d=0;d<a;d++){
        for(int g=0;g<a;g++){
            c[d][g]=0;
        }
    }
    for(int d=0;d<b;d++){
        cin>>f>>e;
        c[f-1][e-1]=1;
        c[e-1][f-1]=1;
    }
    for(int d=0;d<a;d++){
        for(int g=0;g<a;g++){
            cout<<c[d][g];
        }
        cout<<endl;
    }
    return 0;
}