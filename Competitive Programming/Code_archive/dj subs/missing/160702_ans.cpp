// ans.cpp 9 Nov 16, 17:57:50 5 0.91 Judging completed in 8.551s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int v_find(string needle,vector<string> haystack){
    for(int a=0;a<haystack.size();a=a+1){
        if(haystack[a]==needle) return a;
    }
}
int main() {
    vector<string> original;
    int a;
    cin>>a;
    string c;
    for(int b=0;b<a;b=b+1){
        cin>>c;
        original.push_back(c);
    }
    for(int b=0;b<(a-1);b=b+1){
        cin>>c;
        original.erase(original.begin()+v_find(c,original));
    }
    cout<<original[0];
    return 0;
}