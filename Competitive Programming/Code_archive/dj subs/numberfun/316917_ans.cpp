// ans.cpp 17 Jan 18, 19:43:39 0 0.08 Judging completed in 4.366s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, j;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	for (int x=0; x<n; x++){
		int num = arr[x];
		j=0;
		while(num>0){
			if(num%2 == 0){
				num/=2;
				j++;
			}
			else if(num%3 == 0){
				num/=3;
				j++;
			}
			else if(num%2!=0 and num%3!=0){
				num-=1;
				j++;
			}
		}
		while (num>0){
			j=0;
			if ((num-1)%2==0){
				num = (num-1)%2;
			}

		}
		cout << j << "\n";
	}
	
}