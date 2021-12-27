// ans.cpp 29 Oct 17, 20:15:39 0 0.89 Judging completed in 4.055s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<int>s;
    auto it=s.begin();
    int n,b,size=0,cur=0;
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a=="PUSH"){
            cin>>b;
            s.insert(b);
            size++;
        }else{
            auto it=s.begin();
            if((size%2)==0){
                //it+=(size/2);
                //it--;
                //advance(it,(size/2)-1);
                while(cur!=((size/2) -1)){
                    if(cur>((size/2)-1)){
                        cur--;
                        it--;
                    }else{
                        cur++;
                        it++;
                    }
                }
            }else{
                //it+=(size/2);
                //advance(it,size/2);
                while(cur!=(size/2)){
                    if(cur>(size/2)){
                        cur--;
                        it--;
                    }else{
                        cur++;
                        it++;
                    }
                }
            }
            s.erase(it);
            size--;
        }
    }
    it=s.begin();
    for(int x=0;x<size;x++){
        cout<< *it;
        if(x+1<size)cout<<' ';
        it++;
    }
    return 0;
}