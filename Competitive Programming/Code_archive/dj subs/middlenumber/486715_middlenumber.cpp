// middlenumber.cpp 4 Feb 19, 15:01:58 0 0.08 Judging completed in 13.023s on AWS Oregon.
#include "middlenumber.h"
#include<bits/stdc++.h>
using namespace std;
int n,a,b;
multiset<int> front,back;//2 since easier to deal with
multiset<int>::iterator it;
//ensures front always has more or same
inline int median(){
    it=front.end();
    it--;
    a=*it;
    b=*back.begin();
    if((n%2)==0){
        return (b-a)/2 + a;//prevent overflow
    }else{
        return a;
    }
}
int init(int* arr, int length) {
    n=length;
    sort(arr,arr+length);
    for(int x=0;x<length;x++){
        if(x*2<length)front.insert(arr[x]);
        else back.insert(arr[x]);
    }
    return median();
}

int add_number(int x) {
    n++;return 0;
    if((n%2)==0){
        if(n==0){
            front.insert(x);
        }else if(x<= *back.begin()){
            front.insert(x);
        }else{
            back.insert(x);
            front.insert(*back.begin());
            back.erase(back.begin());
        }
    }else{
        it=front.end();
        it--;
        if(*it <= x){
            back.insert(x);
        }else{
            back.insert(*it);
            front.erase(it);
            front.insert(x);
        }
    }
    n++;
    return median();;
}

int remove_number(int x){
    if((n%2)==0){
        it=back.find(x);
        if(it!=back.end())back.erase(it);
        else{
            front.erase(front.find(x));
            front.insert(*back.begin());
            back.erase(back.begin());
        }
    }else{
        it=front.find(x);
        if(it!=front.end())front.erase(it);
        else{
            back.erase(back.find(x));
            it=front.end();
            it--;
            back.insert(*it);
            front.erase(it);
        }
    }
    n--;
    return median();
}

int change_number(int oldx, int newx) {
    remove_number(oldx);
    return add_number(newx);
}