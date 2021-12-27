// ans.cpp 10 Nov 20, 20:25:49 100 0.22 Judging completed in 3.692s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long tally, max_sum;
int main() {
    long long tally = 0, min_sum = 0, N, useless; cin >> N;
    vector<long long> nums;
    /*
    for (int i = -1000; i < 1000; i++){
        k.push_back(i);
    }
    */
    for (int i = 0; i < N; i++){
        cin >> useless;
        //useless = k[rand()%2001];
        nums.push_back(useless);
        //cout << i << ". " << useless << '\n';
    }
    //cout << '\n';
    for (int i = 0; i < N; i++){
      /*
        if (i%20 == 0){
          cout << "I'm still alive" << '\n';
        }*/
        tally += nums[i];
        if (tally > 0){
            tally = 0;
        }else{
            if (tally < min_sum){
                min_sum = tally;
                //cout << min_sum << ' ' << i << '\n';
            }
        }
    }
    if (min_sum == 0){
        min_sum=INT_MAX;
        for (long long i = 0; i < N; i++){
            min_sum=min(min_sum,nums[i]);
        }
    }
    cout << min_sum;
}