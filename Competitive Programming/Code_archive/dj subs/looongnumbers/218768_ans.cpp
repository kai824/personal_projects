// ans.cpp 13 Aug 17, 15:37:48 80 0 Judging completed in 5.475s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
char a[30],b[30];
int main() {
    cin>>a>>b;
    int add=0,arr[max(strlen(a),strlen(b))]={0},i,x,y;
    
    for (i=1;i<=min(strlen(a),strlen(b));i++){
      x=a[strlen(a)-i]-'0';
      y=b[strlen(b)-i]-'0';
      arr[max(strlen(a),strlen(b))-i]=(x+y+add)%10;
      if (x+y+add-10>=0){
        add=(x+y+add)/10;
      }
      else add=0;

    }
    if (strlen(a)>strlen(b)){
      for (i=1;i<=(strlen(a)-strlen(b));i++){
        arr[(strlen(a)-strlen(b))-i]=(a[(strlen(a)-strlen(b))-i]-'0'+add)%10;
        if (a[(strlen(a)-strlen(b))-i]-'0'+add-10>=0){
          add=1;
        }
        else add=0;
      }
    }
    else if (strlen(b)>strlen(a)){
      for (i=1;i<=(strlen(b)-strlen(a));i++){
        arr[(strlen(b)-strlen(a))-i]=(b[(strlen(b)-strlen(a))-i]-'0'+add)%10;
        if (b[(strlen(b)-strlen(a))-i]-'0'+add-10>=0){
          add=1;
        }
        else add=0;
      }
    }
    if (add==1) {
      cout<<"1";
    }
    
    
    for (i=0;i<max(strlen(a),strlen(b));i++){
      cout<<arr[i];
    }
}