// dna.cpp 16 Nov 16, 22:42:17 0 0 Compilation failed on AWS Ireland.
#include "dna.h"
#include <iostream>
#include <vector>
using namespace std;

/*Unfinished: Deriving the answer of the test without 
testing based on previous results*/
string analyse(int n, int t){
    vector<string> i;
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
                i.push_back("00")
                break;
            }else if(make_test("10")){
                ans="10";
                i += "00","01";
                break;
            }else{
                i += "00","01","10";
                ans="11";
            }
        }
        for(int x=2;x<n;x=x+1){
            if(nm_front==false){
                if(make_test(ans+"0")) ans=ans+"0";
                else if(make_test(ans+"1")){
                    ans=ans+"1";
                    i.push_back(ans+"0");
                }else if(make_test("0"+ans)){
                    ans="0"+ans;
                    i += (ans+"0"),(ans+"1");
                    nm_front=true;
                }else{
                    ans="1"+ans;
                    i += (ans+"0"),(ans+"1"),("0"+ans);
                    nm_front=true;}
                }
            else if(make_test("0"+ans)){
                ans="0"+ans;
                i += (ans+"0"),(ans+"1");
                nm_front=true;
            }else{ans="1"+ans;
                i += (ans+"0"),(ans+"1"),("0"+ans);
                nm_front=true;}
        }
        return ans;
    }
}