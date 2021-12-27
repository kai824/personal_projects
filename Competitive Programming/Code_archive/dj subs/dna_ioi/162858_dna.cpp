// dna.cpp 17 Nov 16, 20:53:28 0 0 Compilation failed on AWS Ireland.
#include "dna.h"
#include <iostream>
#include <vector>
using namespace std;

bool test(vector<string> v,string p){//v is the false stuff,p is the main input;
    int a;
    if(v.size()>=250)a=250;
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
        bool nm_back=false, nm_front=false;
        string ans,tester;
        if(n>=10 && make_test("0000000000")){
            ans="0000000000";
            break;
        }else if(n>=10 && make_test("1111111111")){
            ans="1111111111";
            break;
        }else if(make_test("00")){
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
        while(ans.length()<n){
            if(nm_back==false){
                if(test(i,(ans+"0"))) ans=ans+"0";
                else if(n-ans.length()>=2 && nm_front==false){
                    if(test(i,(ans+"10"))){
                        i.push_back(ans+"0");
                        ans=ans+"10";
                    }else if(test(i,(ans+"11"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10")});
                        ans=ans+"11";
                    }else if(test(i,(ans+"1"))){
                    	ans=ans+"1";
                        i.insert(i.end(),{(ans+"0"),(ans+"10"),(ans+"11")});
                        nm_back=true;
                    }
                    else{
                    	nm_back=true;
                    	i.insert(i.end(),{(ans+"0"),(ans+"1")});
                    }
                }else if(nm_front==true){
                	i.push_back(ans+"0");
                	ans=ans+"1";
                }else{
                    if(test(i,(ans+"1"))){
                        i.push_back(ans+"0");
                        ans=ans+"1";
                    }
                    else {
                    	i.insert(i.end(),{(ans+"0"),(ans+"1")});
                    	nm_back=true;
                    }
                }
            }
           if(ans.length()==n) break;
           if(nm_front==false){
                if(test(i,("0"+ans))) ans="0"+ans;
                else if(n-ans.length()>=2 && nm_back==false){
                    if(test(i,("01"+ans))){
                        i.push_back("0"+ans);
                        ans="01"+ans;
                    }else if(test(i,("11"+ans))){
                        i.insert(i.end(),{("0"+ans),("01"+ans)});
                        ans="11"+ans;
                    }else if(test(i,("1"+ans))){
                    	ans="1"+ans;
                        i.insert(i.end(),{("0"+ans),("01"+ans),("11"+ans)});
                        nm_front=true;
                    }
                    else{
                    	nm_front=true;
                    	i.insert(i.end(),{("0"+ans),("1"+ans)});
                    }
                }else if(nm_back==true){
                	i.push_back("0"+ans);
                	ans="1"+ans;
                }else{
                    if(test(i,("1"+ans))){
                        i.push_back("0"+ans);
                        ans="1"+ans;
                    } else{
                    	i.insert(i.end(),{("0"+ans),("1"+ans)});
                    	nm_front=true;
                    }
                }
            }
        }
        return ans;
    }
}