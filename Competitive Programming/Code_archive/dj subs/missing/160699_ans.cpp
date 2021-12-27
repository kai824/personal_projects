// ans.cpp 9 Nov 16, 17:29:50 5 1.09 Judging completed in 9.051s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int v_find(string needle,vector<string> haystack){
    for(int a=0;a<haystack.size();a=a+1){
        if(haystack[a]==needle) return 1;
    }
    return 0;
}
int main() {
    vector<string> original;
    vector<string> one_gone;
    int a;
    cin>>a;
    string c,ans;
    for(int b=0;b<a;b=b+1){
        cin>>c;
        original.push_back(c);
    }
    for(int b=0;b<(a-1);b=b+1){
        cin>>c;
        one_gone.push_back(c);
    }
    for(int b=0;b<a;b=b+1){
        if(v_find(original[b],one_gone)==0){
            ans=original[b];
            break;
        }
    }
    cout<<ans;
    return 0;
}