// ans.cpp 3 Jun 17, 20:30:10 100 0 Judging completed in 9.916s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int b,r=0,c;
    string a;
    cin>>a;
    b=sqrt(a.length());
    for(int x=1;x<=b;x++){
        if(a.length()%x==0){
            r=x;
        }
    }
    c=a.length()/r;
    char matrix[r][c];
    for(int x=0;x<a.length();x++){
        matrix[x%r][x/r]=a[x];
    }
    for(int x=0;x<r;x++){
    	for(int y=0;y<c;y++){
    		cout<<matrix[x][y];
    	}
    }
    return 0;
}