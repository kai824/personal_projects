// ans.cpp 3 Jun 17, 21:00:48 0.02 0.04 Judging completed in 3.506s on AWS Oregon.
#include<bits/stdc++.h>
main(int n){
	std::cin>>n;
	for(int x=1;x<=n;x++){
		for(int y=1;y<x;y++){
			std::cout<<y<<' ';
		}
		std::cout<<x<<'\n';
	}
}