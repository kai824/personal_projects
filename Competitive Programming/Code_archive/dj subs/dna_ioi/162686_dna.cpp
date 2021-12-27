// dna.cpp 16 Nov 16, 16:21:15 0 0.01 Judging completed in 11.935s on AWS Ireland.
#include "dna.h"
#include <iostream>
using namespace std;

string analyse(int n, int t){
    if(n==1){
        if(make_test("0")==true) return "0";
        else return "1";
    }else{
        bool nm_front=false;
        string ans,tester;
        for(int x=0;x<1;x=x+1){
            if(make_test("00")){
                ans="00";
                break;
            }else if(make_test("01")){
                ans="01";
                break;
            }else if(make_test("10")){
                ans="10";
                break;
            }else if(make_test("11")){
                ans="11";
            }
        }
        for(int x=2;x<=n;x=x+1){
            if(nm_front==false){
                if(make_test(ans+"0")) ans=ans+"0";
                else if(make_test(ans+"1"))ans=ans+"1";
                else if(make_test("0"+ans)){
                    ans="0"+ans;
                    nm_front=true;
                }else{
                    ans="1"+ans;
                    nm_front=true;}
                }
            else if(make_test("0"+ans)){
                ans="0"+ans;
                nm_front=true;
            }else{ans="1"+ans;
            nm_front=true;}
        }
        return ans;
    }
}