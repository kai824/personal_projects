// middlenumber.cpp 1 Mar 17, 20:53:35 20 1 Judging completed in 6.523s on AWS Ireland.
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
    int lo=0,hi=length-1,mid;
    while(lo<hi){
        mid=lo+((hi-lo)/2);
        if(myarr[mid]==y){
            lo=mid;
            break;
        }else if(myarr[mid]<y)lo=mid+1;
        else hi=mid;
    }
    myarr.erase(myarr.begin()+lo);
    length--;
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}

int change_number(int oldx, int newx) {
    int lo=0,hi=length-1,mid;
    while(lo<hi){
        mid=lo+((hi-lo)/2);
        if(myarr[mid]==oldx){
            lo=mid;
            break;
        }else if(myarr[mid]<oldx)lo=mid+1;
        else hi=mid;
    }
    myarr[lo]=newx;
    sort(myarr.begin(),myarr.end());
    if(length%2==0){
        return(myarr[(length/2)-1]+((myarr[length/2]-myarr[(length/2)-1])/2));
    }else{
        return(myarr[length/2]);
    }
}