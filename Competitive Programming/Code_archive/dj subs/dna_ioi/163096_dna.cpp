// dna.cpp 18 Nov 16, 20:22:01 36 0.52 Judging completed in 11.366s on AWS Ireland.
#include "dna.h"
#include <iostream>
#include <vector>
using namespace std;

bool test(vector<string> v,string p){//v is the false stuff,p is the main input;
    for(int c=0;c<v.size();c++){
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
    }else if(n>100){
        bool nm_back=false,nm_back2=false,nm_front=false,nm_front2=false;
        string ans,tester;
        if(make_test("1")==false){
            ans="";
            for(int z=0;z<n;z++){
                ans=ans+"0";
            }
            return ans;
        }
        if(make_test("00")){
            ans="00";
        }else if(make_test("01")){
            ans="01";
            i.push_back("00");
        }else if(make_test("10")){
            ans="10";
            i.insert(i.end(),{"00","01"});
        }else{
            ans="";
            for(int z=0;z<n;z++){
                ans=ans+"1";
            }
            return ans;
        }
        while(ans.length()<n){
            if(nm_back==false){
                if(test(i,(ans+"0"))) ans=ans+"0";
                else if(n-ans.length()>=2 && nm_front==false){
                    if(test(i,(ans+"10"))){
                        i.push_back(ans+"0");
                        ans=ans+"10";
                    }else if(nm_back2==false && n-ans.length()>=3 && test(i,(ans+"110"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10")});
                        ans=ans+"110";
                    }else if(nm_back2==false && n-ans.length()>=4 && test(i,(ans+"1110"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10"),(ans+"110")});
                        ans=ans+"1110";
                    }else if(nm_back2==false && n-ans.length()>=5 && test(i,(ans+"11110"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10"),(ans+"110"),(ans+"1110")});
                        ans=ans+"11110";
                    }else if(nm_back2==false && n-ans.length()>=5 && test(i,(ans+"11111"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10"),(ans+"110"),(ans+"1110"),(ans+"11110")});
                        ans=ans+"11111";
                    }else if(test(i,(ans+"1"))){
                        i.insert(i.end(),{(ans+"0"),(ans+"10"),(ans+"110"),(ans+"1110")});
                    	  ans=ans+"1";
                        nm_back2=true;
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
    else{
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
        for(int x=2;x<n;x=x+1){
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