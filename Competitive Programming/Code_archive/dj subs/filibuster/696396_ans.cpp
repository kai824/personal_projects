// ans.cpp 8 Feb 20, 12:51:49 9 4.02 Judging completed in 9.45s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/
string s,t;int a,b;
pair<string,int> arr[300005];
bool cmp(pair<string,int>aa,pair<string,int>bb){
	if(aa.first==bb.first){
		return aa.second>bb.second;
	}
	return aa.first<bb.first;
}

inline char lesss(string & ss){
    //compare ss with the substring...
    for(int x=0;true;x++){
        if(a+x>=b && x>=ss.length()){
            return '=';
        }
				if(a+x>=b){//substring is prefix of ss
					return '>';
				}
				if(x>=ss.length()){//ss is a prefix of substring
					return '<';
				}
        if(ss[x]>s[a+x]){
            return '>';
        }
        if(ss[x]<s[a+x]){
            return '<';
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>s;//full string...
	int n,q,p;
	int lo,hi,mid;
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>p>>t;//copy speaker p, add t to the end...
		arr[x].first=arr[p].first;
		arr[x].first+=t;
		arr[x].second=x;
	}
	sort(arr+1,arr+n+1,cmp);
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b;
		a--;
		t=s.substr(a,b-a);
		if(lesss(arr[1].first)=='>'){
			cout<<"-1\n";
			continue;
		}

		//t=s.substr(a,b-a);

		lo=1;hi=n;
		while(lo<hi){//finding largest string that's less than t...
		    mid=hi-(hi-lo)/2;
		    if(lesss(arr[mid].first)!='>'){//mid less than substring
		        lo=mid;
		    }else{//greater
		        hi=mid-1;
		    }
				//cout<<lo<<' '<<hi<<'\n';
		}
		//t=s.substr(a,b-a);
		//p=upper_bound(arr+1,arr+n+1,make_pair(t,INT_MAX))-1-arr;
		cout<<arr[lo].second<<'\n';
	}
	return 0;
}

/*
weneedtopassanewhealthcarebill
5
0 russian
0 as
2 set
0 blue
4 donkey
4
10 12
27 30
1 30
24 26
*/