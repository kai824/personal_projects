// ans.cpp 3 Jun 17, 21:01:17 0.04 0.03 Judging completed in 3.383s on AWS Oregon.
#include<iostream>
main(int n){
	std::cin>>n;
	for(int x=1;x<=n;x++){
		for(int y=1;y<x;y++){
			std::cout<<y<<' ';
		}
		std::cout<<x<<'\n';
	}
}