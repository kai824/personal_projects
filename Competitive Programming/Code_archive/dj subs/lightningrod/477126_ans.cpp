// ans.cpp 13 Jan 19, 22:01:19 100 0.46 Judging completed in 8.484s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
inline int readi() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}
int main() {
    int n=readi(),a=readi(),b=readi();
    vector<pair<int,int> > v;
    v.push_back(make_pair(a,b));
    for(int x=1;x<n;x++){
        a=readi();b=readi();
        while(true){
            if(v.size()==0){
                v.push_back(make_pair(a,b));
                break;
            }
            if(a-v.back().first<=b-v.back().second){
                //current covers last one...
                v.pop_back();
            }else if(a-v.back().first<=v.back().second-b){
                //last one covers current one
                break;//since no need to push in anymore
            }else{
				v.push_back(make_pair(a,b));
				break;
			}
        }
    }
    cout<<v.size();
    return 0;
}