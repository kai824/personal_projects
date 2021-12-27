// ans.cpp 19 Nov 16, 14:07:56 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int h,w;
    string b;
    vector<string> wall;
    cin>>h>>w;
    for(int a=0;a<h;a++){
        cin>>b;
        wall.push_back(b);
    }
    vector<int> d;
    vector<vector<long long int> > ways;
    for(int a=0;a<h;a++){
        d.clear();
        for(int b=0;b<w;b++){
            if(a==0 && b==0) d.push_back(1);
            else if(wall[a][b]=='X'){
                d.push_back(-1);
            }else if(wall[a][b]=='.') d.push_back(0);
        }
        ways.push_back(d);
    }
    for(int a=0;a<h;a++){
        for(int b=0;b<w;b++){
            if(wall[a][b]!='X'){
                if(a!=0){
                    if(wall[a-1][b]!='X')ways[a][b]+=ways[a-1][b];
                }
                if(b!=0){
                    if(wall[a][b-1]!='X'){
                        ways[a][b]+=ways[a][b-1];
                    }
                }
            }
            ways[a][b]=ways[a][b]%1000000007;
        }
    }
    cout<<ways[h-1][w-1]%1000000007;
    return 0;
}