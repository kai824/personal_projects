// dna.cpp 17 Nov 16, 16:03:49 36 0.4 Judging completed in 7.765s on AWS Ireland.
#include "dna.h"
#include <iostream>
#include <vector>
using namespace std;

bool test(vector<string> v,string p){//v is the false stuff,p is the main input;
    int a;
    if(v.size()>=100)a=100;
    else a=v.size();
    for(int c=0;c<a;c++){
        if (p.find(v[c])!=string::npos){
        	return false;
        }
    }
    return(make_test(p));
}

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
                i.push_back("00");
                break;
            }else if(make_test("10")){
                ans="10";
                i.insert(i.end(),{"00","01"});
                break;
            }else{
                i.insert(i.end(),{"00","01","10"});
                ans="11";
            }
        }
        for(int x=2;x<n;x=x+1){
            if(nm_front==false){
                if(test(i,(ans+"0"))) ans=ans+"0";
                else if(test(i,(ans+"1"))){
                    i.push_back(ans+"0");
                    ans=ans+"1";
                }else if(test(i,("0"+ans))){
                    i.insert(i.end(),{(ans+"0"),(ans+"1")}  );
                    ans="0"+ans;
                    nm_front=true;
                }else{
                    i.insert(i.end(),{(ans+"0"),(ans+"1"),("0"+ans)});
                    ans="1"+ans;
                    nm_front=true;
                }
            }
            else if(test(i,("0"+ans))){
                i.insert(i.end(),{(ans+"0"),(ans+"1")});
                ans="0"+ans;
            }else{
                i.insert(i.end(),{(ans+"0"),(ans+"1"),("0"+ans)});
                ans="1"+ans;
            }
        }
        return ans;
    }
}