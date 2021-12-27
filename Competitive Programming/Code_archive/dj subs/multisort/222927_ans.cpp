// ans.cpp 16 Oct 17, 22:36:58 100 0 Judging completed in 4.259s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,i1,i,x;
    vector <int> z;
    vector <vector<int> >v;
    
    cin>>n>>m;
    for (i1=0;i1<n;i1++){
    	for (i=0;i<m;i++){
    		cin>>x;
    		z.push_back(x);
    	}
    	sort(z.begin(),z.end());
    	v.push_back(z);
    	z.clear();
    }
    sort(v.begin(),v.end());
    for (i1=0;i1<n;i1++){
    	for (i=0;i<m;i++){
    		if (i!=0)cout<<" ";
    		cout<<v[i1][i];
    	}
    cout<<endl;
    }
}