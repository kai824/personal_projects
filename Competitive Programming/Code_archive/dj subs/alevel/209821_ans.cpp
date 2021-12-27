// ans.cpp 9 Jun 17, 20:53:27 55 0 Judging completed in 3.798s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x,i,i1=0;
    priority_queue<double, vector<double>, greater<double> > pq;

    bool b=false;
    char a[20];
    double sum=0;
    cin>>a;
    for (i=0;i<strlen(a);i++){
      if (a[i]=='/'){
        b=true;
        if (i1>3){
          sum+=pq.top()/2;
          pq.pop();
        }
        while(!pq.empty()){
          sum+=pq.top();
          pq.pop();
        }
      }
      else i1++;
      if (a[i]=='A'){
        if (b==true){
          sum+=10;
        }
        else {
          pq.push(20);
          
        }
      }
      else if (a[i]=='B'){
        if (b==true){
          sum+=8.75;
        }
        else {
          pq.push(17.5);
        }
      }
      else if (a[i]=='C'){
        if (b==true){
          sum+=7.5;
        }
        else {
          pq.push(15);
        }
      }
      else if (a[i]=='D'){
        if (b==true){
          sum+=6.25;
        }
        else {
          pq.push(12.5);
        }
      }
      else if (a[i]=='E'){
        if (b==true){
          sum+=5;
        }
        else {
          pq.push(10);
        }
      }
      else if (a[i]=='S'){
        if (b==true){
          sum+=2.5;
        }
        else {
          pq.push(5);
        }
      }
      else if (a[i]=='U'){
        if (b==false){
          pq.push(0);
        }
        
      }
      
      
    }
    if( (sum + 0.5) >= (int(sum) + 1) )
        cout<<int(sum)+1;
    else
        cout<<int(sum);
}