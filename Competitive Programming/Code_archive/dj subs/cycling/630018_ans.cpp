// ans.cpp 4 Dec 19, 18:07:45 0 0.1 Judging completed in 4.703s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,int> mm;
int main() {
    ios_base::sync_with_stdio(false);
    
    int n, m, s;
    cin >> n >> m >> s;
    
    for(int i = 0;i < m;i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        if(a == s) mm[c]++;
        else if(b == s) mm[c]++;
    }
    
    cout << (mm.begin())->second;
    
}