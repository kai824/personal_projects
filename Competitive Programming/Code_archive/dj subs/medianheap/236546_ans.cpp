// ans.cpp 29 Oct 17, 19:38:27 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<int32_t>s;
    auto it=s.begin();
    int n,b,size=0;
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a=="PUSH"){
            cin>>b;
            s.insert(b);
            size++;
        }else{
            it=s.begin();
            if((size%2)==0){
                //it+=(size/2);
                //it--;
                advance(it,(size/2)-1);
            }else{
                //it+=(size/2);
                advance(it,size/2);
            }
            s.erase(it);
            size--;
        }
    }
    auto it=s.begin();
    for(int x=0;x<size;x++){
        cout<< *it;
        if(x+1<size)cout<<' ';
        it++;
    }
    return 0;
}