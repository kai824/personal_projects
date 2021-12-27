// ans.cpp 9 Aug 17, 13:52:50 100 0 Judging completed in 6.789s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
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