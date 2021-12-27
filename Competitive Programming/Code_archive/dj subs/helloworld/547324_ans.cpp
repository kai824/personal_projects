// ans.cpp 4 Aug 19, 23:29:42 0 0 Compilation failed on AWS Oregon.
// Eight queens
#include <bits/stdc++.h>
using namespace std;
long long row, col, row_posn[100], cnt=0, n, sum=0;
//bool r_exist[100]={false}, d1_exist[100]={false}, d2_exist[100]={false},c_exist[100]={false};//all one indexed
bitmask<100> r_exist,d1_exist,d2_exist,c_exist;
bool check[100][100],bef[100][100];

inline long long d1(long long x, long long y){
    return x+y-1;
}

inline long long d2(long long x, long long y){
    return x-y+n;
}
inline void search(long long c) {
	if ( c==n+1 ) {
		sum++;     
        return;
	}
 	if ( c_exist[c] ) {
        search(c+1);
    }
	else { // test queen in each row and check 
	//cout<<c<<'\n';
	   for (long long i=1;i<=n;i++){
	       //cout<<c<<" "<<i<<" "<<r_exist[i]<<" "<<d1_exist[d1(c,i)]<<" "<<d2_exist[d2(c,i)]<<'\n';
       if (!r_exist[i]&&!d1_exist[d1(c,i)]&&!d2_exist[d2(c,i)]&&!check[i][c]){
          r_exist[i]=c_exist[c]=d1_exist[d1(c,i)]=d2_exist[d2(c,i)]=1;
          search(c+1);
          //cout<<c<<'\n';
		  r_exist[i]=c_exist[c]=d1_exist[d1(c,i)]=d2_exist[d2(c,i)]=1;
       }
     }
	   
	   
	}
	   
	   
	
	//cout<<c<<'\n';
    // by default function always return here
}

int main(){
	//ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long q,b;
	long long precomp[100]={1,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184,14772512,95815104,666090624,4968057848,39029188884,314666222712};
	sum=0;
	cin>>n;
	cin>>q;
	for (long long i=0;i<q;i++){
		// input the initial queen position and covert to zero base
		cin >> row >> col;
		// record the queen's row position and mark the occupied row and diagonals 
		if (!r_exist[row]&&!d1_exist[d1(col,row)]&&!d2_exist[d2(col,row)]){
			c_exist[col]=r_exist[row]=d1_exist[d1(col,row)]=d2_exist[d2(col,row)]=1;
		}
		else{
			cout<<0<<'\n';
			return 0;

		}
		bef[row][col]=true;
	}
	cin>>b;
	for (long long i=0;i<b;i++){
		sum=0;
		// input the initial queen position and covert to zero base
		cin >> row >> col;
		// record the queen's row position and mark the occupied row and diagonals
		if (bef[row][col]==false)check[row][col]=true;
		else {
			cout<<0<<'\n';
			return 0;
		}
		
	}
	if (q==0&&b==0){
		cout<<precomp[n]<<'\n';
		cout<<"Trying it out...\n";
		//return 0;
	}
	clock_t begin=clock();
	search(1);
	clock_t end=clock();
	cout<<sum<<'\n';
	cout<<"This took "<<(double)(end-begin)/CLOCKS_PER_SEC;
	return 0;
}