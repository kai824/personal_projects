// ans.cpp 10 Nov 20, 20:21:39 100 0 Judging completed in 3.337s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long c1[10005];//dp array
long long c2[10005];
int main(){
	int n;
	cin >> n;
	int arr[n], arr2[n];
	int a,b;
	cin  >> a >> b;
	c1[0] = a;
	c2[0] = b;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		cin >> arr2[i];
	}
	int arr3[n-1], arr4[n-1];//transition timing
	int x,y;
	for(int i=0;i<n-1;i++){
		cin >> arr4[i];
	}
	for(int i=0;i<n-1;i++){
		cin >> arr3[i];
	}
	cin >> x >> y;
	for(int i=0;i<n;i++){
	    if(i == 0){
	        c1[i+1] = c1[0] + arr[i];
	        c2[i+1] = c2[0] + arr2[i];
	        continue;
	    }
		c1[i+1] = min(c1[i] + arr[i], c2[i] + arr3[i-1] + arr[i]);
		c2[i+1] = min(c2[i] + arr2[i], c1[i] + arr4[i-1] + arr2[i]);
	}
	long long c = c1[n];
	long long d = c2[n];
	c += x;
	d += y;
	cout << min(c , d);
}