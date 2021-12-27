// ans.cpp 10 Feb 18, 13:56:48 0 0.08 Judging completed in 8.931s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,ll> mp;
void main2(ll n){
    //...

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,tmps,tmpe,sx,sy,ex,ey;
    cin>>n;
    /*(if(n<105){
        main2(n);
        //return 0;
    }*/
    string a;
    cin>>a;//the colours...
    //dao subtask 3, assume they don't repeat
    for(ll x=0;x<=a.length();x++){
        mp[a[x]]=x+1;
    }
    //generate my square numbers to look up...
    set<ll> squares;
    map<ll,ll> mp2;
    for(ll x=0;x<1000000;x++){
        if(x*x>100000)break;
        squares.insert(x*x);
        mp2[x*x]=x;
    }
    ll q;
    cin>>q;
    ll si,ei;
    char sc,ec;
    for(ll x=0;x<q;x++){
        cin>>si>>sc>>ei>>ec;
        si=((si-1)*n)+mp[sc];//1 indexed
        ei=(ei-1)*n+mp[ec];
        set<ll>::iterator ite=squares.upper_bound(si);
        ite--;
        tmps=*ite;//the largest square number smaller or equal to it
        tmpe=mp2[tmps];
        if((tmpe%2)==0){
            if(si==tmps){
                sx=tmpe/2;sy=sx;
                sy--;
            }else if(si-tmps<=tmpe){
                //top row...
                sx=tmpe/2;sy=sx;
                sx-=si-tmps-1;
            }else{
                //left row...
                tmps+=tmpe+1;
                sx=-(tmpe/2);sy=-sx;
                sy-=si-tmps;
            }
        }else{
            if(si-tmps>tmpe){
                //right row...
                tmps+=tmpe+1;
                sx=(tmpe+1)/2;sy=-sx;
                sy+=si-tmps;
            }else if(si==tmps){
                sx=-(tmpe/2);
                sy=sx;
            }else{
                //bottom row...
                sx=-(tmpe/2);
                sy=sx;
                sy--;
                sx+=si-tmps-1;
            }
        }

        ite=squares.upper_bound(ei);
        ite--;
        tmps=*ite;//the largest square number smaller or equal to it
        tmpe=mp2[tmps];
        if((tmpe%2)==0){
            if(ei==tmps){
                ex=tmpe/2;ey=ex;
                ey--;
            }else if(ei-tmps<=tmpe){
                //top row...
                ex=tmpe/2;ey=ex;
                ex-=ei-tmps-1;
            }else{
                //left row...
                tmps+=tmpe+1;
                ex=-(tmpe/2);ey=-ex;
                ey-=ei-tmps;
            }
        }else{
            if(ei-tmps>tmpe){
                //right row...
                tmps+=tmpe+1;
                ex=(tmpe+1)/2;ey=-ex;
                ey+=ei-tmps;
            }else if(ei==tmps){
                ex=-(tmpe/2);
                ey=ex;
            }else{
                //bottom row...
                ex=-(tmpe/2);
                ey=ex;
                ey--;
                ex+=ei-tmps-1;
            }
        }
        cout<<(abs(sx-ex)+abs(sy-ey))<<'\n';
    }
    return 0;
}