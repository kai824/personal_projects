// ans.cpp 9 Nov 20, 11:02:21 100 0.21 Judging completed in 3.555s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, x;
    cin >> N;
    long long arr[N];
    long long maxsum = 0;
    long long sum=0;
    
    for (int i = 0; i < N; i++){
        cin >> x;
        arr[i] = -x;
    }
    
    bool all_neg=true;
    for(int i=0; i < N; i++){
    if(arr[i]>0)all_neg=false;
    }
    
    if (all_neg==false){
        //kadane algorithm
        for (int i = 0; i < N; i++){
            sum += arr[i];
            if (sum < 0)
            sum = 0;
            if (maxsum < sum)
            maxsum = sum;
        }
    }
    
    if (all_neg==true){
        maxsum = arr[0];
        for (int i = 1; i < N; i++){
            if (arr[i] > maxsum)
            maxsum = arr[i];
        }
    }
    
    cout << -maxsum;
    
}