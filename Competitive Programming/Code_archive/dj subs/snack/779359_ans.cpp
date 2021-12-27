// ans.cpp 9 Nov 20, 11:52:20 100 0.05 Judging completed in 5.893s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, maxsum=0, sum = 0;
    cin >> N;
    string str;
    cin >> str;
    int arr[N];
    
    for (int i = 0; i < N; i++){
        if (str[i]=='M')
        arr[i] = -2;
        else
        arr[i] = (str[i]-'0');
    }
    
    for (int i = 0; i < N; i++){
        sum += arr[i];
        if (sum < 0)
        sum = 0;
        if (maxsum < sum)
        maxsum = sum;
    }
    
    cout << maxsum << "\n"; 
    
}