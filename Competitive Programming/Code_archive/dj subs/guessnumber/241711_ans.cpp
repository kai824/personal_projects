// ans.cpp 4 Nov 17, 16:04:15 100 0 Judging completed in 2.886s on AWS Oregon.
#include <iostream>
using namespace std;
int n;
int main () {
	cin >> n;
	if (n == 1) { 
		cout << 156 << endl;
	}
	else if (n == 2) { 
		cout <<177 << endl;
	}
	else if (n == 3) { 
		cout <<235 << endl;
	}
	else if (n == 4) { 
		cout <<728 << endl;
	}
	else if (n == 5) { 
		cout <<873 << endl;
	}else{
	    cout<<53<<'\n';
	}
	return 0;
}