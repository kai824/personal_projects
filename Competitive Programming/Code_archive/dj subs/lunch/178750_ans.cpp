// ans.cpp 7 Jan 17, 17:41:55 100 0 Judging completed in 4.331s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    short int a;
    cin>>a;
    if(a<3)cout<<"That's a terrible potato!";
    else if(a<6)cout<<"That's a normal potato!";
    else if(a<9)cout<<"That's a good potato!";
    else cout<<"OMG POTATOES!!!";
    return 0;
}