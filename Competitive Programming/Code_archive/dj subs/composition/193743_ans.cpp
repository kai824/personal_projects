// ans.cpp 22 Feb 17, 09:25:18 0 0.05 Judging completed in 5.957s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    map<char,int> a;
    vector<int> c;
    a['a']=1;
    a['b']=2;
    a['c']=3;
    a['d']=4;
    a['e']=5;
    a['f']=6;
    a['g']=7;
    a['h']=8;
    a['i']=9;
    a['j']=10;
    a['k']=11;
    a['l']=12;
    a['m']=13;
    a['n']=14;
    a['o']=15;
    a['p']=16;
    a['q']=17;
    a['r']=18;
    a['s']=19;
    a['t']=20;
    a['u']=21;
    a['v']=22;
    a['w']=23;
    a['x']=24;
    a['y']=25;
    a['z']=26;
    int n,l,ans=0;
    string b;
    cin>>n>>l;
    for(int x=0;x<n;x++){
        cin>>b;
        for(int y=0;y<b.length();y++){
            if(isalpha(b[y]))ans+=a[b[y]];
        }c.push_back(ans);
        ans=0;
    }
    sort(c.begin(),c.end(),cmp);
    for(int y=0;y<l;y++){
        ans+=c[y];
    }cout<<ans;
    return 0;
}