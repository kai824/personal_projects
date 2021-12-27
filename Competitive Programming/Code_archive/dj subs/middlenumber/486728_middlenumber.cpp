// middlenumber.cpp 4 Feb 19, 15:14:01 100 0.14 Judging completed in 4.329s on AWS Oregon.
#include "middlenumber.h"
#include<bits/stdc++.h>
using namespace std;

vector<int> myarr;
int length;

int init2(int arr[], int len) {
    length=len;
    for(int x=0;x<length;x++){
        myarr.push_back(arr[x]);
    }
    sort(myarr.begin(),myarr.end());
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}
int add_number2(int x) {
    length++;
    myarr.push_back(x);
    sort(myarr.begin(),myarr.end());
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}
int remove_number2(int y) {
    for(int x=0;x<length;x++){
        if(myarr[x]==y){
            myarr.erase(myarr.begin()+x);
            break;
        }
    }length--;
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}

int change_number2(int oldx, int newx) {
    for(int x=0;x<length;x++){
        if(myarr[x]==oldx){
            myarr[x]=newx;
            break;
        }
    }
    sort(myarr.begin(),myarr.end());
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}

bool cheating=false;
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
    if(length<=100){
        cheating=true;
        return init2(arr,length);
    }
    n=length;
    sort(arr,arr+length);
    for(int x=0;x<length;x++){
        if(x*2<length)front.insert(arr[x]);
        else back.insert(arr[x]);
    }
    return median();
}

int add_number(int x) {
    if(cheating)return add_number2(x);
    if((n%2)==0){
        if(n==0){
            front.insert(x);
        }else if(x<= *back.begin()){
            front.insert(x);
        }else{
            front.insert(*back.begin());
            back.erase(back.begin());
            back.insert(x);
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
    if(cheating)return remove_number2(x);
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
    if(cheating)return change_number2(oldx,newx);
    remove_number(oldx);
    return add_number(newx);
}