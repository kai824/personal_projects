// ans.cpp 14 Dec 19, 14:35:13 0 0.03 Judging completed in 3.862s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    vector<short int> v;
    while (cin >> x){
        v.push_back(x);
    }
    for (int i=0; i<v.size(); i++){
        cout << v[v.size()-1-i] << '\n';
    }
}