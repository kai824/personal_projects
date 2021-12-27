// ans.cpp 11 Nov 20, 13:50:54 100 0 Judging completed in 3.271s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

deque<char>hunny[105];

void erasehunny(int i,int j) {
    if (hunny[i+1][j]=='H') {
        hunny[i+1][j]='.';
        erasehunny(i+1,j);
    }
    if (hunny[i][j+1]=='H') {
        hunny[i][j+1]='.';
        erasehunny(i,j+1);
    }
    if (j!=0) {
    if (hunny[i][j-1]=='H') {
        hunny[i][j-1]='.';
        erasehunny(i,j-1);
    } }
    if(i>0){
        if (hunny[i-1][j]=='H') {
            hunny[i-1][j]='.';
            erasehunny(i-1,j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int r,c; cin>>r>>c;
    string temp;
    for (int i=0; i<r; i++) {
        cin>>temp;
        for (int j=0; j<c; j++) {
            hunny[i].push_back(temp[j]);
        }
    }
    int numhunny=0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (hunny[i][j]=='H') {
                erasehunny(i,j);
                numhunny++;
            }
        }
    }
    cout<<"Oh, bother. There are "<<numhunny<<" pools of hunny.";
    return 0;
}