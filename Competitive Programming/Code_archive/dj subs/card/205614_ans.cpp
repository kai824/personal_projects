// ans.cpp 1 May 17, 20:03:39 100 0 Judging completed in 6.75s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,b;
    string a;
    cin>>n>>k>>a;
    deque<int> deck;
    for(int x=0;x<n;x++){
        deck.push_back(x);
    }
    for(int x=0;x<a.length();x++){
        if(a[x]=='A'){
            deck.push_back(deck[0]);
            deck.pop_front();
        }else if(a[x]=='B'){
            deck.push_back(deck[1]);
            b=deck[0];
            deck.pop_front();
            deck.pop_front();
            deck.push_front(b);
        }
    }
    cout<<deck[k-1]<<' '<<deck[k]<<' '<<deck[k+1];
    return 0;
}