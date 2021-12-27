// ans.cpp 23 Oct 16, 18:28:45 0 0 Judging completed in 5.242s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string input;
    int a,b,c;
    vector<int> V;
    cin>>a>>b;
    cin>>input;
    istringstream stream(input);
    while(stream>>c)
        V.push_back(c);
    cout<<V[b-1];
    return 0;
}