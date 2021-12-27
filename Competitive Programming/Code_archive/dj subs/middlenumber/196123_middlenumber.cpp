// middlenumber.cpp 1 Mar 17, 20:33:14 20 1 Judging completed in 5.122s on AWS Ireland.
#include "middlenumber.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> myarr;
int length;

int init(int arr[], int len) {
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
int add_number(int x) {
    length++;
    myarr.push_back(x);
    sort(myarr.begin(),myarr.end());
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}
int remove_number(int y) {
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

int change_number(int oldx, int newx) {
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