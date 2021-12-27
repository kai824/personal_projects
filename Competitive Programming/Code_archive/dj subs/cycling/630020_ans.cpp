// ans.cpp 4 Dec 19, 18:08:56 0 0.1 Judging completed in 4.871s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,set<int> > mm;
int main() {
    ios_base::sync_with_stdio(false);
    
    int n, m, s;
    cin >> n >> m >> s;
    
    for(int i = 0;i < m;i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        if(a == s) mm[c].insert(b);
        else if(b == s) mm[c].insert(a);
    }
    
    for(int x : mm.begin()->second) cout << x << " ";
    
}