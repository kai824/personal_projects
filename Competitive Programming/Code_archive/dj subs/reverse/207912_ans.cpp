// ans.cpp 24 May 17, 20:03:28 0 1 Judging completed in 17.207s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,current="",answer="";//current as in current word
    getline(cin,s);
    for(int x=0;x<s.length();x++){
        if(isalpha(s[x])){
            current=current+" ";
            current[current.length()-1]=s[x];
        }else if(current==""){
            answer=answer+" ";
            answer[answer.length()-1]=s[x];
        }else{
            for(int y=current.length()-1;y>=0;y--){
                answer=answer+" ";
                if(isupper(current[current.length()-1-y])){
                    answer[answer.length()-1]=toupper(current[y]);
                }else{
                    answer[answer.length()-1]=tolower(current[y]);
                }
            }
            current="";
            answer=answer+" ";
            answer[answer.length()-1]=s[x];
        }
    }
    cout<<answer;
    return 0;
}