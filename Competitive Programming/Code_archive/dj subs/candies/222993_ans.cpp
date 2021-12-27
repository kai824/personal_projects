// ans.cpp 17 Oct 17, 11:45:01 100 0.65 Judging completed in 4.867s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[1000005],n;
int arr[1000005];
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a,b,lo,hi,mid;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if(a==1){//buy the candy
            if(b<1000005){
            
            if(arr[b]==0){
                update(b,1);
            }
            arr[b]++;
            
            }
        }else{//eat the candy
            if(b<1000005 && arr[b]>0){
            
            arr[b]--;
            if(arr[b]==0){
                update(b,-1);
            }
            
            }
        }
        
        lo=0;hi=n;
        while(lo<hi){
        	mid=(lo+hi);
        	mid-=(lo+hi)/2;
        	if(collection(mid)){
        		lo=mid;
        	}else{
        		hi=mid-1;
        	}
        }
        cout<<lo<<'\n';
        //output
    }
    return 0;
}