// ans.cpp 29 Mar 17, 20:58:48 100 1.98 Judging completed in 7.477s on AWS Ireland.
#include "primepie.h"
#include <bits/stdc++.h>
using namespace std;

long long int amountEaten(int N) {
    vector<int> primes;
    bool broke;
    int numberEaten=0,current=2,testno;
    long long ans=0;
    while(numberEaten<N){
        testno=0;
        broke=false;
        for(int x=0;(x<primes.size() && primes[testno]*primes[testno]<=current);x++){
            if(current%primes[testno]==0){
                broke=true;
                break;
            }else{
                testno++;
            }
        }
        if(!broke){//meaning that the current number is prime.
            ans+=current;
            primes.push_back(current);
            numberEaten++;
        }
        current++;
    }
    return ans;
}