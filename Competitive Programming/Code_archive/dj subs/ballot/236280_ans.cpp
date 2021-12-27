// ans.cpp 29 Oct 17, 16:28:02 100 0.13 Judging completed in 4.122s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,c,a;
    cin>>n>>c;
    multimap<int,int> s;
    for(int x=1;x<=n;x++){
        cin>>a;
        s.insert(make_pair(a,x));
    }
    for(int x=0;x<c;x++){
        cin>>a;
        auto lo=s.lower_bound(a);
        auto hi=s.upper_bound(a);
        if(hi==s.end()){
        	hi=lo;
        	hi--;
        	if(lo==s.begin() || abs(lo->first-a)<abs(hi->first-a)){
            cout<<lo->second<<'\n';
            s.erase(lo);
        	}else{
        		cout<<hi->second<<'\n';
        		s.erase(hi);
        	}
        }else if(hi==s.begin()){
        	cout<<hi->second<<'\n';
        	s.erase(hi);
        }else if(abs(lo->first-a)<=abs(hi->first-a)){
        	hi=lo;
        	hi--;
        	if(lo==s.begin() || abs(lo->first-a)<abs(hi->first-a)){
            cout<<lo->second<<'\n';
            s.erase(lo);
        	}else{
        		cout<<hi->second<<'\n';
        		s.erase(hi);
        	}
        }else{
            cout<<hi->second<<"\n";
            s.erase(hi);
        }
    }
    return 0;
}