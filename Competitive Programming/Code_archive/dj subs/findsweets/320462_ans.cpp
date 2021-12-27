// ans.cpp 1 Feb 18, 10:14:10 100 0 Judging completed in 2.93s on AWS Oregon.
#include "findsweets.h"
using namespace std;
int arr[100005];
int find_special_sweets(int N, int A, int B){
    long long a=0;
    for(int x=1;x<=N;x++){
        arr[x]=x;
        a+=x;
    }
    long long ans=weigh(arr);
    ans-=(a*A);
    ans/=(B-A);
    return ans;
}