// ans.cpp 9 Apr 17, 21:15:32 100 0 Judging completed in 6.625s on AWS Oregon.
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