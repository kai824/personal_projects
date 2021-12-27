// ans.cpp 14 Dec 19, 14:36:33 0 0.02 Judging completed in 6.009s on AWS Oregon.
#include <iostream>
#include<vector>
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