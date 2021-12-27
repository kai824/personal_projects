// ans.cpp 11 Feb 17, 18:03:05 0 0 Compilation failed on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[500][1000005],ft2[500][1000005],n1,n2;//n1 is vertical,n2 is horizontal
int ls(int x){
	return(x&(-x));
}
int hquery(int a,int p){//horizontal row a, first p elements.
	int sum=0;
	for(;p;p-=ls(p))sum+=ft[a][p];
	return sum;
}
int query(int p, int a){
	int sum=0;
	for(;p;p-=ls(p))sum+=hquery(p,a);
	return sum;
}
void hupdate(int a,int b,int c){//add c to row a element b
	for(;b<=n2;b+=ls(b)){
		ft[a][b]+=c;
	}
}
void update(int p,int a,int v){//adds v to tree[p][a]
	for(;p<=n1;p+=ls(p)){
		//ft[p]+=v;
		hupdate(p,a,v);
	}
}
int hquery2(int a,int p){//horizontal row a, first p elements.
	int sum=0;
	for(;p;p-=ls(p))sum+=ft2[a][p];
	return sum;
}
int query2(int p, int a){
	int sum=0;
	for(;p;p-=ls(p))sum+=hquery2(p,a);
	return sum;
}
void hupdate2(int a,int b,int c){//add c to row a element b
	for(;b<=n2;b+=ls(b)){
		ft2[a][b]+=c;
	}
}
void update2(int p,int a,int v){//adds v to tree[p][a]
	for(;p<=n1;p+=ls(p)){
		//ft[p]+=v;
		hupdate2(p,a,v);
	}
}
int main(){
    int k,q,b,c,d,e,f;
	cin>>n1>>n2>>k>>q;
	string a;
	for(int x=0;x<q;x++){
	    cin>>a>>b>>c>>d;
	    if(a=="feed"){
	        if((b+c)%2==0){
	            update(b,c,d%2);
	        }else update2(b,c,d%2);
	    }else{
	        cin>>k;
	        e=query(d,k)-query(b-1,c-1);
	        f=query2(d,k)-query2(b-1,c-1);
	        cout<<min(min(e+(((d-b+1)*(k-c+1))/2)-f,(d-b+1)*(k-c+1)-(e+(((d-b+1)*(k-c+1))/2)-f)),min(f+(((d-b+1)*(k-c+1))/2)-e,(d-b+1)*(k-c+1)-(f+(((d-b+1)*(k-c+1))/2)-e)))<<endl;
	    }
	}
	return 0;
}