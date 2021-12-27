// ans.cpp 17 Oct 17, 16:03:28 0 3.05 Judging completed in 8.802s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[10000005],n,c,a,s,e;
bool arr[10000005];
int ls(int x){
	return(x & (-x));
}
int query(int p){//sum of first p elements
	int sum=0;
	for(;p;p-=ls(p))sum+=ft[p];
	return sum;
}
void update(int p,int v){
	for(;p<=(n+5);p+=ls(p)){
		ft[p]+=v;//n is the number of elements
	}
}
bool collection(int x){
	if(x==0)return true;
	else return(query(x)==x);
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n>>c;
    for(int x=0;x<c;x++){
        cin>>a;
        if(arr[a]==false){
            arr[a]=true;
            cout<<a<<'\n';
            update(a,1);
        }else{
        
        s=0;e=a-1;
        while(s<e){
            if( ( query(e) - query( (s+e)/2 ) ) != (e-((s+e)/2)) ){
                //if equal, all between e and that is occupied
                s=(s+e)/2;
                s++;
            }else{
                e=(s+e)/2;
            }
        }
        if(s!=0){
        cout<<s<<'\n';
        update(s,1);
        }else{
        s=a+1;e=n;
        while(s<e){
            if( ( query(e) - query( (s+e)/2 ) ) != (e-((s+e)/2)) ){
                //if equal, all between e and that is occupied
                s=(s+e)/2;
                s++;
            }else{
                e=(s+e)/2;
            }
        }
        cout<<s<<'\n';
        update(s,1);
        }
        
        }
    }
    return 0;
}