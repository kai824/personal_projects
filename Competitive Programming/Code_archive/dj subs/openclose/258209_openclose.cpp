// openclose.cpp 16 Nov 17, 12:33:58 100 0 Judging completed in 2.219s on AWS Oregon.
#include<cstdio>
#include<string>
using namespace std;

string openorclose(int N, string *Q){
    if(N%2==0)return "close";
    return "open";
}