// ans.cpp 29 Mar 17, 20:55:07 48 3 Judging completed in 11.402s on AWS Ireland.
#include "primepie.h"
#include <bits/stdc++.h>
using namespace std;

long long int amountEaten(int N) {
    vector<int> primes;
    bool broke;
    int numberEaten=0,current=2,testno;
    long long ans=0;
    while(numberEaten<N){
        testno=2;
        broke=false;
        while(testno*testno<=current){
            if(current%testno==0){
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