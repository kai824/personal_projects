// ans.cpp 10 Oct 17, 09:01:16 66.67 1 Judging completed in 4.658s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string add(string a,char b,int c){
  if(a.length()-c<=0)a="0"+a;
  int digit=((a[a.length()-c]-'0')+(b-'0'));
  a[a.length()-c]=(digit%10)+'0';
  if(digit/10>=1)a=add(a,(digit/10)+'0',c+1);
  return a;
}
string sum(string a,string b){
  int c=1;
  for(int x=b.length()-1;x>=0;x--){
    a=add(a,b[x],c);
    c++;
  }
  if(a[0]=='0')a.erase(0,1);
  return a;
}
bool t2(string a){while(true){}
    return(((a[a.length()-1]-'0')%2)==0);
}
bool t3(string a){while(true){}
    int b=0;
    for(int x=0;x<a.length();x++){
        b+=a[x]-'0';
    }
    return((b%3)==0);
}
bool t4(string a){
    return ((((a[a.length()-2]-'0')*10) + (a[a.length()-1]-'0')%4)==0);
}
bool t5(string a){
    return(a[a.length()-1]=='5' || a[a.length()-1]=='0');
}
bool t6(string a){
    return(t2(a)&&t3(a));
}
bool t7(string a){
    string b;
    while(a.length()>7){
        b=" ";
        b[0]=a[a.length()-1];
        a.erase(a.length()-1,1);
        b=sum(sum(b,sum(b,b)),sum(b,b));
        a=sum(a,b);
    }
    int d=0;
    while(a.length()>0){
        d*=10;
        d+=a[0]-'0';
        a.erase(0,1);
    }
    return((d%7)==0);
}
bool t8(string a){
    int b=a[a.length()-3]-'0';
    b*=100;
    b+=(a[a.length()-2]-'0')*10;
    b+=a[a.length()-1]-'0';
    return((b%8)==0);
}
bool t9(string a){
    int b=0;
    for(int x=0;x<a.length();x++){
        b+=a[x]-'0';
    }
    return((b%9)==0);
}
bool t10(string a){
    return(a[a.length()-1]=='0');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n,k,ans=0;
    bool b;
    string a;
    cin>>n>>k;
    if(n==1){
        cout<<k;return 0;
    }
    for(int x=0;x<k;x++){
        cin>>a;//functions return true if divisible
        if(n==2){
            b=t2(a);
        }if(n==3){
            b=t3(a);
        }if(n==4){
            b=t4(a);
        }if(n==5){
            b=t5(a);
        }if(n==6){
            b=t6(a);
        }if(n==7){
            b=t7(a);
        }if(n==8){
            b=t8(a);
        }if(n==9){
            b=t9(a);
        }if(n==10){
            b=t10(a);
        }
        if(b)ans++;
    }
    cout<<ans;
    return 0;
}