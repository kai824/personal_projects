// ans.cpp 24 Nov 19, 17:00:32 40 0.08 Judging completed in 4.492s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
    if(a.length()==b.length())return a>b;
    return a.length()>b.length();
}
bool cmp2(string a,string b){
    for(int x=0;x<min(a.length(),b.length());x++){
        if(a[x]!=b[x])return a[x]>b[x];
    }
	string c;bool bb;
	if(a.length()>b.length())c=a,bb=true;
	else c=b,bb=false;
	for(int x=0;x<min(a.length(),b.length()) && x+min(a.length(),b.length())<c.length();x++){
		if(a[x]!=c[x+min(a.length(),b.length())]){
			return (a[x]>c[x+min(a.length(),b.length())])^bb;
		}
	}
    return a.length()<b.length();
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin>>n>>k;
    string arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n,cmp);
    sort(arr,arr+k,cmp2);
    for(int x=0;x<k;x++){
        cout<<arr[x];
    }
    return 0;
}