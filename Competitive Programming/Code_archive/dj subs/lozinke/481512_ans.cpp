// ans.cpp 24 Jan 19, 21:03:11 100 0.28 Judging completed in 2.923s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    return (a.length()<b.length());
}
int main() {
    int n,ans=0;
    cin>>n;
    string arr[n],cur;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n,cmp);
    map<string,int> mp;
	vector<string> v;
    for(int x=0;x<n;x++){
        for(int i=0;i<arr[x].length();i++){
            cur="";
            for(int j=i;j<arr[x].length();j++){
                cur=cur+" ";
                cur[cur.length()-1]=arr[x][j];
                //new substring generated in cur
                v.push_back(cur);
            }
        }
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(i>0 && v[i]==v[i-1])continue;
			if(mp.find(v[i])!=mp.end()){
				ans+=mp[v[i]];
				if(v[i].length()==arr[x].length())ans+=mp[v[i]];
			}
		}
		v.clear();
        if(mp.find(arr[x])==mp.end())mp[arr[x]]=1;
        else mp[arr[x]]+=1;
    }
    cout<<ans;
    return 0;
}