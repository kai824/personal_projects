// ans.cpp 9 Nov 20, 21:50:57 87 0.22 Judging completed in 6.588s on AWS Oregon.
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
      long long min_num;
        for (long long i = 0; i < N-1; i++){
            min_num = min(nums[i], nums[i+1]);
            if (min_num < min_sum || min_sum == 0){
              min_sum = min_num;
            }
        }
    }
    cout << min_sum;
}