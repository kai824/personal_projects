// cave.cpp 26 Aug 17, 19:43:27 100 0.31 Judging completed in 6.12s on AWS Oregon.
#include "cave.h"
#include<bits/stdc++.h>
using namespace std;
bool used[5005],change;
vector<int> v;
void exploreCave(int n){
    int ans[n],attempt[n],c,a=-2,b,ans2[n],a2,b2;
    for(int x=0;x<n;x++){
        ans[x]=-1;//storing just for the final thing to return
                  //when calling ans...
        attempt[x]=0;//the array to put into the function...
        ans2[x]=-1;//the array that stores all the
                   //right (there) positions of the switch...
    }
    for(int x=0;x<n;x++){//figure out how to open door x...
        if(change||x==0)a2=tryCombination(attempt);
        else b2=a2;
        if(a2==-1||a2>x){
        	a=1;
        }else{
        	a=0;
        }
        v.clear();
        for(int y=0;y<n;y++){
            if(!used[y]){
                v.push_back(y);
            }
        }
        while(v.size()>1){
            //v shall store all the switches
            //that might unlock door x...
            for(int y=0;y<(v.size()/2);y++){
                attempt[v[y]]=!attempt[v[y]];
            }
            b2=tryCombination(attempt);
            if(b2==-1||b2>x){
            	b=1;
            }else{
            	b=0;
            }
            if(a==b){
                for(int y=0;y<(v.size()/2);y++){
                    attempt[v[y]]=!attempt[v[y]];
                }
                for(int y=0;y<(v.size()/2);y++){
                    swap(v[y],v.back());
                    v.pop_back();
                }
            }else{
                b=v.size()/2;
                while(v.size()>b){
                    v.pop_back();
                }
                for(int y=0;y<v.size();y++){
                    attempt[v[y]]=!attempt[v[y]];
                }
            }
        }
        //Now that the loop has ended, size of v should be 1...
        //We learn that v[0] is the key to door x...
        used[v[0]]=true;
        ans[v[0]]=x;
        if(a==1){
            ans2[v[0]]=attempt[v[0]];
        }else ans2[v[0]]=!attempt[v[0]];
        change=true;
        if(attempt[v[0]]==ans2[v[0]])change=false;
        attempt[v[0]]=ans2[v[0]];
    }
    answer(ans2,ans);
}
/*
answer: return all the doors each key is connected to.
e.g. if door 1 is connected to switch 2, door 2 is
connected to switch 1, answer returns(... , [2,1]);*/