// ans.cpp 21 May 17, 21:39:36 100 0 Judging completed in 5.449s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<int> fibo={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733};
int process(int x,int iterator){
	while(true){
		if(fibo[iterator]>x){
			iterator--;
		}else if(fibo[iterator]==x){
			return fibo[iterator];
		}else{
			break;
		}
	}
	return(process(x-fibo[iterator],iterator));
}
int main() {
	int n;
    cin>>n;
    cout<<process(n,fibo.size()-1);
    return 0;
}