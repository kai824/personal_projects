// ans.cpp 8 Mar 17, 20:59:58 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,e,i1,i2,o1,o2;
    cin>>a;
    int b[2][a];
    bool d[a],broke;
    for(int x=0;x<a;x++){
        cin>>b[x];
        d[x]=1;
    }
    while(true){
        e=0;//e refers to the iterator of where to put the next variable into...
        i1=0;
        while(i1<a){
            broke=false;
        for(int x=i1+1;;x++){
            if(x>=a){
                i2=x;
                for(int y=e;y<a;y++)c[y]=b[y];
                broke=true;
                break;
            }
            if(d[x]){
                i2=x;
                break;
            }
        }
        if(broke){
            continue;
        }
        o1=i1;
        o2=i2;
        while(i1<o2 || (!d[i2])){
            if(d[i2]){
                c[e]=b[i1];
                i1++;
                e++;
            }else if(i1>=o2){
                c[2]=b[i2];
                i2++;
                e++;
            }else{
                if(b[i1]<b[i2]){
                    c[e]=b[i1];
                    i1++;
                    e++;
                }else{
                    c[e]=b[i2];
                    i2++;
                }
            }
        }
        i1=i2;
        }
        swap(b,c);
    }
    for(int x=0;x<a;x++){
        cout<<b[x]<<endl;
    }
    return 0;
}