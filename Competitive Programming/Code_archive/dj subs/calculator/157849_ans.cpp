// ans.cpp 2 Nov 16, 10:59:55 65 0 Judging completed in 7.415s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    float a,b;
    char c;
    cin>>a>>c>>b;
    switch(c){
        case '+':
        cout<<a+b;
        break;
        case '-':
        cout<<a-b;
        break;
        case '*':
        cout<<a*b;
        break;
    }
    return 0;
}